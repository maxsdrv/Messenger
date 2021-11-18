#ifndef DATABASE_MULTITHREAD_CONNECTDB_H
#define DATABASE_MULTITHREAD_CONNECTDB_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMutex>
#include <QThread>
#include <QFuture>
#include <QtConcurrent>

class ConnectDb : public QObject {
    Q_OBJECT
public:
    explicit ConnectDb(QObject* parent = nullptr);
    ~ConnectDb();
public slots:
    void init();
    void log(const QString& msg);
private:
    QMutex _mx;
    QSqlDatabase m_connection;
};


#endif //DATABASE_MULTITHREAD_CONNECTDB_H
