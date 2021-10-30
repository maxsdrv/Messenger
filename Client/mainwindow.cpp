#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlRecord>
#include <algorithm>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_connectDb(new ConnectDb()), m_rowCount(0)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);

    if (!m_connectDb->createConnect())
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
    delete m_connectDb;
    qDebug() << "~MainWindow()\n";
}


const int MainWindow::getCountRow() {
    QSqlQuery query;
    query.exec("select count (*) from UserMessages");

    if (query.first()) {
        m_rowCount = query.value(0).toInt();
    }
    return m_rowCount;
}

void MainWindow::on_actiongetMessage_triggered()
{
    QSqlQuery query;
    query.exec("select * from UserMessages");
    if (query.last()) {
        ui->plainTextEdit->appendPlainText(query.value(2).toString());
        ui->statusbar->showMessage(tr("Got message"));
    }
    else ui->statusbar->showMessage(tr("Something went wrong"));
}


void MainWindow::on_actionClear_triggered()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_actiondeleteFromDatabase_triggered()
{
    QSqlQuery query("delete from UserMessages where user_name = 'PC'");

    if (query.exec()) {
        ui->statusbar->showMessage("Database cleared");
    }

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

