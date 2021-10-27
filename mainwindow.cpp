#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->cancelButton, SIGNAL(clicked()), ui->plainTextEdit, SLOT(clear()));

    m_connect = new ConnectDb();
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


//void MainWindow::closeEvent(QCloseEvent *event)
//{
//    QMessageBox::StandardButton resBtn =
//            QMessageBox::question(this, "Messenger", tr("You sure?\n"),
//            QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
//            QMessageBox::Yes);
//    if (resBtn != QMessageBox::Yes) {
//        event->ignore();
//    }
//    else {
//        event->accept();
//    }
//}


