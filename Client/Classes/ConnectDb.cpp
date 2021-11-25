#include "ConnectDb.h"


ConnectDb::ConnectDb(const QString &connectionName) : QObject(nullptr)
{
    //connect to remote database
    m_database = QSqlDatabase::addDatabase("QODBC", connectionName);
    m_database.setDatabaseName("ServerAcerDSN");
    m_database.setUserName("SA");
    m_database.setPassword("pass202mssqlAcer");

    if (!m_database.open())
    {
        qDebug() << "ERROR OPEN DATABASE" << m_database.lastError().text();
    }
}

ConnectDb::~ConnectDb()
{
    qDebug() << "~ConnectDb()";
}

QMutex connect_mutex;

void ConnectDb::getMsg()
{
    bool flag = false;
    for (;;)
    {
        m_database.open();

        QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));

        QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
                "    result |";

        {
            connect_mutex.lock();

            QThread::msleep(10);

            QSqlQuery query(m_database);
            query.exec("select * from Messages");
            if (query.last())
            {
                str += QString::number(query.value(0).toInt()) + " " + query.value(1).toString() + " "
                       + query.value(2).toString() + " " + query.value(3).toString() + " |";
            }

            connect_mutex.unlock();
        }
        QSqlDatabase::removeDatabase(connectionName);
        emit msgResult(str + "\n");
     }
//    m_database.open();

//    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));

//    QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
//            "    result |";

//    {
//        connect_mutex.lock();

//        QThread::msleep(10);

//        QSqlQuery query(m_database);
//        query.exec("select * from Messages");
//        if (query.last())
//        {
//            str += QString::number(query.value(0).toInt()) + " " + query.value(1).toString() + " "
//                   + query.value(2).toString() + " " + query.value(3).toString() + " |";
//        }

//        connect_mutex.unlock();
//    }
//    QSqlDatabase::removeDatabase(connectionName);

//    emit msgResult(str + "\n");

}


