#include "mainwindow.h"
#include "Classes/ConnectDb.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800, 500);
    w.show();
//    ConnectDb *cc = new ConnectDb();
//    if (!cc->createConnect()) {
//        qDebug() << "ERROR\n";
//        delete cc;
//        return EXIT_FAILURE;
//    }
//    delete cc;

    return a.exec();
}
