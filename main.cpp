#include "mainwindow.h"
#include "Classes/ConnectDb.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1000, 1000);
    w.show();
    ConnectDb cc;
    if (!cc.createConnect()) {
        qDebug() << "ERROR\n";
        return EXIT_FAILURE;
    }


    return a.exec();
}
