#include <QCoreApplication>
#include <QDebug>

#include "Classes/ConnectDb.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConnectDb db("Messenger", "LOCALHOST\\SQLEXPRESS");

    return 0;
}
