#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_countMsg(0)
{
    ui->setupUi(this);

//    if (!m_connect->createConnect())
//    {
//        ui->statusbar->showMessage(tr("Error database connection"));
//    }
//    else
//    {
//        ui->statusbar->showMessage(tr("Connection successfull"));
//    }

//    QString dsn = QString ("DRIVER=ODBC Driver 17 for SQL Server;"
//                           "Server=192.168.0.123;Database=Messenger;"
//                           "Uid=sa;Pwd=DataSciec2019");

//    m_connect = new ConnectDb(dsn);
//    QSqlDatabase threadDb = m_connect->createConnect();

    m_Send1 = new Send;
    m_Send2 = new Send;

    connect(&thread_1, &QThread::started, m_Send1, &Send::run);
    connect(&thread_2, &QThread::started, m_Send2, &Send::run);

    connect(m_Send1, &Send::stopSignal, &thread_1, &QObject::deleteLater);
    connect(m_Send2, &Send::stopSignal, &thread_2, &QObject::deleteLater);

    connect(m_Send1, &Send::sendMessage, m_Send2, &Send::setMessage2, Qt::QueuedConnection);

    m_Send1->moveToThread(&thread_1);
    m_Send2->moveToThread(&thread_2);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_connect;
    delete m_Send1;
    delete m_Send2;

    qInfo() << "~MainWindow()\n";

}

const int MainWindow::getCountMsg()
{
    QSqlQuery query;
    query.exec("select count (*) from UserMessages");
    if (query.first()) {
        m_countMsg = query.value(0).toInt();
    }
    return m_countMsg;
}



void MainWindow::on_sendButton_clicked()
{
//    auto text_forDb = ui->plainTextEdit->toPlainText();
//    QSqlQuery query;

//    QString sQuery {"insert into UserMessages values(:id, :user_name, :text)"};
//    query.prepare(sQuery);
//    query.bindValue(":id", getCountMsg() + 1);
//    query.bindValue(":user_name", "PC");
//    query.bindValue(":text", text_forDb);

//    if (query.exec())
//    {
//        ui->statusbar->showMessage(tr("Message sent"));
//        qDebug() << "Record Inserted";
//    }

    m_Send1->setMessage(ui->plainTextEdit->toPlainText());

    m_Send1->setRunning(true);
    m_Send2->setRunning(true);

    thread_1.start();
    thread_2.start();
}

void MainWindow::on_clearButton_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_exitButton_clicked()
{
    thread_1.wait();
    thread_2.wait();
    thread_1.quit();
    thread_2.quit();
    this->close();
}

