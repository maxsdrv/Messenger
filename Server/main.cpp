#include "mainwindow.h"
#include "Classes/client_window.h"
#include "Classes/get_data.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow server;
    ClientWindow client;
    server.resize(800, 500);
    client.resize(800, 500);
    client.move(client.x() + client.width() + 100, client.y());
    server.show();
    client.show();

    return a.exec();
}
