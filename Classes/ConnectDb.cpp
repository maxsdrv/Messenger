#include "ConnectDb.h"



bool ConnectDb::createConnect() {
    db = QSqlDatabase::addDatabase("QODBC"); //declare which driver we will use

    db.setUserName("sa");
    db.setDatabaseName("ServerDSN"); //etc/odbc.ini
    db.setPassword("DataSciec2019");

    if (!db.open()) {
        qDebug() << db.lastError().text();
        return false;
    }
    else {
        QSqlQuery query;
        if (query.exec("select * from UserMessages")) {
            while (query.next()) {
                qDebug() << query.value(1).toString() << query.value(2).toString();
            }
        }
        else {
            qDebug() << "QUERY doesn't processed\n";
            qDebug() << db.lastError().text();
            return false;
        }
    }

    return true;
}

ConnectDb::~ConnectDb() {
    db.close();
    qDebug() << "~ConnectDb()";
}

