#ifndef DATABASE_MULTITHREAD_CONNECTDB_H
#define DATABASE_MULTITHREAD_CONNECTDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

class ConnectDb {
public:
    ConnectDb() = default;
    ~ConnectDb();
    bool createConnect();

private:
    QSqlDatabase db;
};


#endif //DATABASE_MULTITHREAD_CONNECTDB_H
