#ifndef GETTINGTHREAD_H
#define GETTINGTHREAD_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QSqlQuery>

class GettingThread : public QObject
{
    Q_OBJECT
public:
    explicit GettingThread(const QString &connectionName);
    ~GettingThread();
signals:
    void msgResult(const QString &result);
public slots:
    void getMsg();
private:
    QSqlDatabase m_database;
};

#endif // GETTINGTHREAD_H
