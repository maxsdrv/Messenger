#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    int index = 0;
//    for (;;)
//    {
//        MyThread *my_thread = new MyThread;
//        my_thread->setAutoDelete(true);
//        my_thread->setType(index);
//        QThreadPool::globalInstance()->start(my_thread);

//        ++index;
//        if (index > 3)
//            index = 0;
//    }

    m_thread1 = new MyThread2("thread1");
    m_thread2 = new MyThread2("thread2");

    m_thread1->moveToThread(&th1);
    m_thread2->moveToThread(&th2);

    th1.start();
    th2.start();
}

MainWindow::~MainWindow()
{
    delete ui;

    th1.quit();
    th1.wait();
    th2.quit();
    th2.wait();

    qInfo() << "~MainWindow()\n";

}

void MainWindow::start()
{
    QMetaObject::invokeMethod(m_thread1, "test_query");
    QMetaObject::invokeMethod(m_thread2, "test_query");
}

void MainWindow::on_sendButton_clicked()
{
    ui->plainTextEdit->appendPlainText("UI Thread ID: " +
                                       QString::number(*static_cast<int*>(QThread::currentThreadId()), 16));

    start();

    connect(&th1, &QThread::finished, &th1, &QThread::deleteLater);
    connect(&th2, &QThread::finished, &th2, &QThread::deleteLater);

    connect(m_thread1, &MyThread2::query_result, this, [this](const QString &result) {
       ui->plainTextEdit->appendPlainText(result);
    });
    connect(m_thread2, &MyThread2::query_result, this, [this](const QString &result) {
       ui->plainTextEdit->appendPlainText(result);
    });
}

void MainWindow::on_clearButton_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_exitButton_clicked()
{

    this->close();
}
