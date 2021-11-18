#include "mythread2.h"


MyThread2::MyThread2(const QString &connectionName) : QObject(nullptr)
{
    m_database = QSqlDatabase::addDatabase("QODBC", connectionName);
    m_database.setDatabaseName("ServerDSN");
    m_database.setUserName("SA");
    m_database.setPassword("DataSciec2019");
}

QMutex my_thread2_mutex;

void MyThread2::test_query()
{
    m_database.open();

    QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
                                                 "    result: |";
    {
        my_thread2_mutex.lock();

        QSqlQuery query(m_database);
        query.exec("select * from UserMessages");

        while (query.next())
        {
            str += QString::number(query.value(0).toInt()) + query.value(1).toString() + "|";
        }

        my_thread2_mutex.unlock();
    }

    QSqlDatabase::removeDatabase(str);

    emit query_result(str + "\n");
}
