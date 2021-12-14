#include "send_data.h"

SendData::SendData(const QString &connectionName) : QObject(nullptr)
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

SendData::~SendData()
{
    qDebug() << "~SendData()";
}

void SendData::send_query(const QString& msg, const QString &hash)
{
    m_database.open();

    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    qDebug() << "send_query(const QString& msg)" << msg;
    qDebug() << "hash = " << hash;

    //Insert our message into database
    {
        QMutexLocker locker(&m_mutex);
        QSqlQuery query(m_database);
        query.prepare("insert into Messages values(:user_name, :message, :checksum)");
        query.bindValue(":user_name", "PC");
        query.bindValue(":message", msg);
        query.bindValue(":checksum", hash);
        if (query.exec())
        {
            qDebug("record inserted");
        }
    }

    QSqlDatabase::removeDatabase(connectionName);
}

void SendData::getRowsDatabase()

{
    QVariant count_rows{};

    m_database.open();
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    qDebug() << "getRowsDatabase()";

    //Get number of database rows
    {
        QMutexLocker locker(&m_mutex);
        QThread::msleep(10);

        QSqlQuery query(m_database);
        query.prepare("select count (*) from Messages");
        query.exec();
        if (query.next())
        {
            count_rows = query.value(0).toInt();
        }

    }
    QSqlDatabase::removeDatabase(connectionName);
    qDebug() << " numbers of rows " << count_rows;

    emit get_rows_result(count_rows.toString());
}

void SendData::test_Emptiness(const QString &hash)
{
    m_database.open();

    qDebug() << "Test for emptiness database";
    {
        QMutexLocker locker(&m_mutex);
        QSqlQuery query(m_database);
        query.prepare("insert into Messages values(:user_name, :message, :checksum)");
        query.bindValue(":user_name", "SYSTEM");
        query.bindValue(":message", "first start");
        query.bindValue(":checksum", hash);
        if (query.exec()) {
            qDebug() << "Data written successfull";
        }
    }
}











