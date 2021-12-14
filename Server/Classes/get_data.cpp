#include "get_data.h"


GetData::GetData(const QString &connectionName) : QObject(nullptr)
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
    qDebug() << "GetData()";
}


GetData::~GetData()
{
    qDebug("~GetData()");
}

void GetData::getMsg(const QString &hash)
{
    m_database.open();

    qDebug() << "getMsg()";
    qDebug() << "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16);
    qDebug() << "HASH = " << hash;
    //Get connection name from current thread
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));

    QString str; //string with message
    QString temp_hash;
    {
//        QThread::msleep(10);
        QMutexLocker locker(&m_mutex);

        QSqlQuery query1(m_database); //create the request to check if the hash has changed
        query1.prepare("select checksum from Messages");
        query1.exec();
        if (query1.last()) {
            temp_hash = query1.value(0).toString();
            qDebug() << "hash from Client = " << hash;
            qDebug() << "temp hash = " << temp_hash;
        }

        if (hash.isEmpty()) //it spring up when program start
        {
            qDebug() << "HASH IS EMPTY";
            return;
        }

        //The idea behind this approach is to wait for the hash to change
        if (temp_hash != hash) { //compare hashs
            QSqlQuery query2(m_database); // if hashs different create new request
            query2.prepare("select data from Messages");
            query2.exec();
            if (query2.last()) {
                str = query2.value(0).toString();
                qDebug() << "message from GetData = " << str;
                emit msgResult(str); //emit result with the last message which sent us
            }
        }

    }

    QSqlDatabase::removeDatabase(connectionName); // correct close connection
}

void GetData::getHash()
{
    m_database.open();
    qDebug() << "getHash\n";
    qDebug() << "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16);

    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    QString hash;

    // get last hash from database
    {
//        QThread::msleep(10);
        QMutexLocker locker(&m_mutex);

        QSqlQuery query(m_database);

        query.prepare("select checksum from Messages");
        query.exec();
        if (query.last()) {
            hash = query.value(0).toString();
            emit hashResult(hash);
        }
    }

    QSqlDatabase::removeDatabase(connectionName); //correct close connection

}



















