#include "sendingthread.h"

SendingThread::SendingThread(const QString &connectionName) : QObject(nullptr)
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

SendingThread::~SendingThread()
{
    qDebug() << "~SendingThread()";
}

QMutex sending_mutex;
QMutex sending_mutex2;
void SendingThread::send_query(const QString& msg, const QString &hash)
{
    m_database.open();

//    QString str = "Thread ID: " + QString::number(*static_cast<int*>(QThread::currentThreadId()), 16) +
//            "    result: |";
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    qDebug() << "send_query(const QString& msg)" << msg;
    qDebug() << "hash = " << hash;

    {
        sending_mutex.lock();
        QSqlQuery query(m_database);
        query.prepare("insert into Messages values(:user_name, :message, :checksum)");
        query.bindValue(":user_name", "PC");
        query.bindValue(":message", msg);
        query.bindValue(":checksum", hash);
        if (query.exec())
        {
            qDebug("record inserted");
        }
        sending_mutex.unlock();
    }

    QSqlDatabase::removeDatabase(connectionName);
}

void SendingThread::getRowsDatabase()

{
    QVariant count_rows{};

    m_database.open();
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    qDebug() << "getRowsDatabase()";

    {
        sending_mutex2.lock();
        QThread::msleep(10);

        QSqlQuery query(m_database);
        query.prepare("select count (*) from Messages");
        query.exec();
        if (query.next())
        {
            count_rows = query.value(0).toInt();
        }

        sending_mutex2.unlock();
    }
    QSqlDatabase::removeDatabase(connectionName);
    qDebug() << " numbers of rows " << count_rows;

    emit get_rows_result(count_rows.toString());
}











