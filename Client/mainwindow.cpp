#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlRecord>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_thread1 = new ConnectDb("thread2");
    m_thread1->moveToThread(&th1);

    th1.start();
    qDebug() << "thread started\n";

    //Waiting message from Server Database
    ui->plainTextEdit->appendPlainText("UI Thread ID: " +
                                       QString::number(*static_cast<int*>(QThread::currentThreadId()), 16));

    start();

    connect(&th1, &QThread::finished, &th1, &QThread::deleteLater);

    connect(m_thread1, &ConnectDb::msgResult, this, [this](const QString &msg) {
        ui->plainTextEdit->appendPlainText(msg);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
    th1.quit();
    th1.wait();

    delete m_thread1;

    qDebug() << "~MainWindow()\n";
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::start()
{
    QMetaObject::invokeMethod(m_thread1, "getMsg", Qt::QueuedConnection);

}


