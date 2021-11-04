#ifndef DATABASE_MULTITHREAD_CONNECTDB_H
#define DATABASE_MULTITHREAD_CONNECTDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

class ConnectDb {
public:
    ConnectDb(const QString& dbName);
    ~ConnectDb();
    QSqlDatabase createConnect();

private:
    QSqlDatabase db;
    QString m_DbName;
};


#endif //DATABASE_MULTITHREAD_CONNECTDB_H
