#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

#include "ConnectDb.h"


class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(const QString &connectionName);
    ~MyThread();
signals:
    void msg_result(const QString &msg);
public slots:
    void send_msg();
private:
    QSqlDatabase m_database;
};

#endif // MYTHREAD_H
