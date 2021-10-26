#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    label = QSharedPointer<QLabel>(new QLabel(this), doDeleteLater);
//    label = std::make_shared<QLabel>(this);
//    label->setFrameStyle(QFrame::Panel || QFrame::Sunken);
//    label->setText("Hello world");
//    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);


}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow()\n";
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

void MainWindow::doDeleteLater(QLabel *label)
{
    qDebug() << "doDeleteLater()\n";
    label->deleteLater();
}

