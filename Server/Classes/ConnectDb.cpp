#include "ConnectDb.h"


ConnectDb::ConnectDb(QObject *parent)
{
    qDebug("ConnectDb()");
}

ConnectDb::~ConnectDb()
{
    QMutexLocker locker(&_mx);
    QThread::msleep(500);
    qDebug("~ConnectDb()");
}

void ConnectDb::init()
{
    QMutexLocker locker(&_mx);

    QSqlDatabase m_connection = QSqlDatabase::addDatabase("QODBC", "main-connection");
    m_connection.setDatabaseName("ServerDSN");
    m_connection.setUserName("SA");
    m_connection.setPassword("DataSciec2019");
    if (m_connection.contains("ServerDSN")) {
        qDebug("Error database has been already");
    }
    if (!m_connection.open()) {
        qDebug() << "ERROR" << m_connection.lastError().text();
    }


    else {
        qDebug() << "SUCCESSFULL";
    }

}

void ConnectDb::log(const QString& msg)
{
    QThread::msleep(500);
    qDebug() << "ConnectDb::log()" << msg;
}


