#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QCryptographicHash>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_thread1 = new SendData("thread1");
    m_thread2 = new SendData("thread2");

    m_thread1->moveToThread(&th1);
    m_thread2->moveToThread(&th2);

    th1.start();
    th2.start();
}

MainWindow::~MainWindow()
{
    delete ui;
// release(free up) resources
    th1.quit();
    th1.wait();
    th2.quit();
    th2.wait();

    delete m_thread1;
    delete m_thread2;

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
    QMetaObject::invokeMethod(m_thread2, "getRowsDatabase", Qt::QueuedConnection);
    qDebug() << "QMetaObject called";

}


void MainWindow::on_sendButton_clicked()
{
    qDebug() << ("UI Thread ID of Server: " +
                 QString::number(*static_cast<int*>(QThread::currentThreadId()), 16));

    start();

    connect(&th1, &QThread::finished, &th1, &QThread::deleteLater);
    connect(&th2, &QThread::finished, &th2, &QThread::deleteLater);

    connect(m_thread2, &SendData::get_rows_result, this, [this](const QString &result) {
        this->setCountRows(result);
    }); // lambda for calculating rows in table of database
    //calculating hash by the algorithm md5
    auto hash = QString(QCryptographicHash::hash(getCountRows().toStdString().c_str(), QCryptographicHash::Md5).toHex());
    auto text_for_db = ui->plainTextEdit->toPlainText(); // get message from PlainTextEdit

    m_thread1->send_query(text_for_db, hash); //using our method for creating query to database

//    connect(this, &MainWindow::query_result, m_thread1, &SendingThread::send_query);
//    emit query_result(text_for_db, hash);
}

void MainWindow::on_clearButton_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_exitButton_clicked()
{

    this->close();
}
