#include "mythread2.h"


MyThread2::MyThread2(const QString &connectionName) : QObject(nullptr)
{
    //connect to remote database
    m_database = QSqlDatabase::addDatabase("QODBC", connectionName);
    m_database.setDatabaseName("ServerAcerDSN"); //etc/odbc.ini
    m_database.setUserName("SA");
    m_database.setPassword("pass202mssqlAcer");

    if (!m_database.open())
    {
        qDebug() << m_database.lastError().text();
    }

}

MyThread2::~MyThread2()
{
    qDebug() << "~MyThread2()";
}

QMutex my_thread2_mutex; //global variable mutex

void MyThread2::test_query()
{
    m_database.open();

    QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
                                                 "    result: |";
    {
        my_thread2_mutex.lock(); //using mutex for thread-safe

        QSqlQuery query(m_database);
        query.exec("select * from s_Msg"); //send request
        if (query.last()) //look last message
        {
            str += QString::number(query.value(0).toInt()) + " " + query.value(1).toString() +
                    " " + query.value(2).toString() + " " + query.value(3).toString() + "|";
        }

        my_thread2_mutex.unlock();
    }

    QSqlDatabase::removeDatabase(str); //correct remove database

    emit query_result(str + "\n");
}
