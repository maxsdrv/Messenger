#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QThread>

#include "ConnectDb.h"

class MyThread2 : public QObject
{
    Q_OBJECT
public:
    explicit MyThread2(const QString &connectionName);
    ~MyThread2();
signals:
    void query_result(const QString &result);
public slots:
    void test_query();
private:
    QSqlDatabase m_database;
};

#endif // MYTHREAD2_H
