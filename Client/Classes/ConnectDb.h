#ifndef DATABASE_MULTITHREAD_CONNECTDB_H
#define DATABASE_MULTITHREAD_CONNECTDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMutex>
#include <QThread>
#include <QRunnable>

class ConnectDb : public QObject {
    Q_OBJECT
public:
    explicit ConnectDb(const QString &connectionName);
    ~ConnectDb();
signals:
    void msgResult(const QString &result);
public slots:
    void getMsg();
private:
    QSqlDatabase m_database;
};


#endif //DATABASE_MULTITHREAD_CONNECTDB_H
