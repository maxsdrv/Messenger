#include "mythread.h"


MyThread::MyThread(const QString &connectionName) : QObject(nullptr)
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

MyThread::~MyThread()
{
    qDebug() << "~MyThread()";
}

QMutex my_thread1_mutex;

void MyThread::send_msg()
{
    m_database.open();

    QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
            "    result: |";

    my_thread1_mutex.lock();

    QSqlQuery query(m_database);
    query.exec("select * from s_Msg"); //send request
    if (query.last()) //look last message
    {
        str += QString::number(query.value(0).toInt()) + " " + query.value(1).toString() +
                " " + query.value(2).toString() + " " + "|";
    }


    my_thread1_mutex.unlock();

    QSqlDatabase::removeDatabase(str);

    emit msg_result(str + "\n");
}


