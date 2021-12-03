#ifndef GETDATA_H
#define GETDATA_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QSqlQuery>

class GetData : public QObject
{
    Q_OBJECT
public:
    explicit GetData(const QString &connectionName);
    ~GetData();
signals:
    void msgResult(const QString &msg);
    void hashResult(const QString &hash);
public slots:
    void getHash();
    void getMsg(const QString &hash);
private:
    QSqlDatabase m_database;
    mutable QMutex m_mutex;
};

#endif // GETDATA_H
