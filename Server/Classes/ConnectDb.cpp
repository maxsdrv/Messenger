#include "ConnectDb.h"

#include <QThread>

ConnectDb::ConnectDb(const QString& dbName) : m_DbName(dbName) {}

QSqlDatabase ConnectDb::createConnect() {
//    db = QSqlDatabase::addDatabase("QODBC"); //declare which driver we will use

//    db.setUserName("sa");
//    db.setDatabaseName("ServerDSN"); //etc/odbc.ini
//    db.setPassword("DataSciec2019");

//    if (!db.open()) {
//        qDebug() << db.lastError().text();
//        return false;
//    }

//    return true;




    QString dbName = QStringLiteral("%1_%2").arg(m_DbName).arg(qintptr(QThread::currentThreadId()), 0, 16);
    if(QSqlDatabase::contains(dbName))
    {
        db = QSqlDatabase::database(dbName);
    }
    else {
        db = QSqlDatabase::addDatabase(QStringLiteral("QODBC"), dbName);
        db.setUserName("sa");
        db.setDatabaseName("ServerDSN");
        db.setPassword("DataSciec2019");
        if (!db.open()) {
            qDebug() << db.lastError().text();
        }
        else qDebug() << "Connection to database successfull\n";
    }
    return db;
}


ConnectDb::~ConnectDb() {
    db.close();
    qInfo() << "~ConnectDb()";
}

