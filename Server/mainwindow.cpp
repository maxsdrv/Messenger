#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QCryptographicHash>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    th1.reset(new QThread);
    th2.reset(new QThread);
    m_thread1.reset(new SendData("thread1"));
    m_thread2.reset(new SendData("thread2"));

    m_thread1->moveToThread(th1.get());
    m_thread2->moveToThread(th2.get());

    th1->start();
    th2->start();
}

MainWindow::~MainWindow()
{
    delete ui;

    QMetaObject::invokeMethod(this, "cleanup");
    th1->wait();
    th2->wait();

    qInfo() << "~MainWindow()\n";

}

void MainWindow::setCountRows(const QString &count)
{
    m_count_rows = count;
}

const QString &MainWindow::getCountRows() const
{
    return m_count_rows;
}


void MainWindow::start()
{
    QMetaObject::invokeMethod(m_thread2.get(), "getRowsDatabase", Qt::QueuedConnection);
    QMetaObject::invokeMethod(m_thread1.get(), "test_Emptiness", Qt::QueuedConnection,
                              Q_ARG(const QString&, m_hash));
    qDebug() << "QMetaObject called";

}


void MainWindow::on_sendButton_clicked()
{
    qDebug() << ("UI Thread ID of Server: " +
                 QString::number(*static_cast<int*>(QThread::currentThreadId()), 16));

    start();

    connect(m_thread2.get(), &SendData::get_rows_result, this, [this](const QString &result) {
        this->setCountRows(result);
    }); // lambda for calculating rows in table of database

    //calculating hash by the algorithm md5
    QString hash;
    if (getCountRows().toInt() == 0) {
        qDebug() << "Database is empty. Adding necesseary data...";
        hash = QString(QCryptographicHash::hash(getCountRows().toStdString().c_str() + 1,
                       QCryptographicHash::Md5).toHex());
    }
    else
    hash = QString(QCryptographicHash::hash(getCountRows().toStdString().c_str(),
                                                 QCryptographicHash::Md5).toHex());



    auto text_for_db = ui->plainTextEdit->toPlainText(); // get message from PlainTextEdit

    ui->plainTextEdit->clear(); //clear field after sent message

    m_thread1->send_query(text_for_db, hash); //using our method for creating query to database

    connect(th1.get(), &QThread::finished, th1.get(), &QThread::deleteLater);
    connect(th2.get(), &QThread::finished, th2.get(), &QThread::deleteLater);
}

void MainWindow::on_clearButton_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_exitButton_clicked()
{

    this->close();
}

void MainWindow::cleanup()
{
    th1->quit();
    th2->quit();
    qDebug() << "cleanup of MainWindow()";
}
