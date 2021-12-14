#include "client_window.h"
#include "ui_client_window.h"

#include <QTimer>
#include <QFuture>
#include <QtConcurrent>

ClientWindow::ClientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    m_thread1.reset(new QThread);
    m_thread2.reset(new QThread);

    m_get_data1.reset(new GetData("1"));
    m_get_data2.reset(new GetData("2"));

    m_get_data1->moveToThread(m_thread1.get());
    m_get_data2->moveToThread(m_thread2.get());

    m_thread1->start();
    m_thread2->start();


    ui->ClientMessage->insertPlainText("thread start: " + QString::number(*static_cast<int*>
                                            (m_thread1->currentThreadId()), 16) + "\n");

    connects_To_Database();
}

ClientWindow::~ClientWindow()
{

    QMetaObject::invokeMethod(this, "cleanup");
    m_thread1->wait();
    m_thread2->wait();

    qDebug() << "~Client()";
}

void ClientWindow::on_pushButton_Exit_clicked()
{
    this->close();
}


void ClientWindow::on_pushButton_Clear_clicked() {
    ui->ClientMessage->clear();
}

void ClientWindow::cleanup()
{
    m_thread1->quit();

    m_thread2->quit();

    qDebug() << "cleanup of ClientWindow()";
}


void ClientWindow::start()
{
    QMetaObject::invokeMethod(m_get_data1.get(), "getHash");

    QMetaObject::invokeMethod(m_get_data2.get(), "getMsg",
                              Q_ARG(const QString&, m_hash));
}


void ClientWindow::connects_To_Database()
{
    connect(&m_timer, &QTimer::timeout, this, &ClientWindow::start);
    m_timer.start(5000);


    connect(m_get_data1.get(), &GetData::hashResult, this, [this](const QString &result) {
        m_hash = result;
    });

    connect(m_get_data2.get(), &GetData::msgResult, this, [this](const QString &result) {
        qDebug() << "message = " << result;
        ui->ClientMessage->insertPlainText(result + '\n');
    });



    connect(m_thread1.get(), &QThread::finished, m_thread1.get(), &QThread::deleteLater);
    connect(m_thread2.get(), &QThread::finished, m_thread2.get(), &QThread::deleteLater);
}






