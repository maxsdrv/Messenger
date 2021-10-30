#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_connect(new ConnectDb()), m_countMsg(0)
{
    ui->setupUi(this);

    if (!m_connect->createConnect())
    {
        ui->statusbar->showMessage(tr("Error database connection"));
    }
    else
    {
        ui->statusbar->showMessage(tr("Connection successfull"));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_connect;
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
    auto text_forDb = ui->plainTextEdit->toPlainText();
    QSqlQuery query;

    QString sQuery {"insert into UserMessages values(:id, :user_name, :text)"};
    query.prepare(sQuery);
    query.bindValue(":id", getCountMsg() + 1);
    query.bindValue(":user_name", "PC");
    query.bindValue(":text", text_forDb);

    if (query.exec())
    {
        ui->statusbar->showMessage(tr("Message sent"));
        qDebug() << "Record Inserted";
    }

}

void MainWindow::on_cancelButton_clicked()
{
    ui->plainTextEdit->clear();
}

