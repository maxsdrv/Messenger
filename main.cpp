#include <QCoreApplication>
#include <QDebug>
#include <QSql>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";

    return QCoreApplication::exec();
}
