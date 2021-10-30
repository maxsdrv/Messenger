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

    return true;
}


ConnectDb::~ConnectDb() {
    db.close();
    qInfo() << "~ConnectDb()";
}

