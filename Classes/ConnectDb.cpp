#include "ConnectDb.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>


ConnectDb::ConnectDb(const QString &nameDb, const QString &sN) {
    // Connect to database
    const QString& serverName = sN;
    const QString& dbName = nameDb;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setConnectOptions();

    QString dsn = QString ("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;")
            .arg (serverName, dbName);
    db.setDatabaseName(dsn);

    if (db.open()) {
        qDebug() << "OPENED SUCCESSFULLY!";
        db.close();
    }
    else {
        qDebug() << "ERROR::DATABASE CANNOT OPEN!" << db.lastError().text();
    }
}

ConnectDb::~ConnectDb() {
    qDebug() << "~ConnectDb()";
}

