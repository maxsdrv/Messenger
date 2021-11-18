#include "mythread.h"


MyThread::MyThread(QObject *parent) : QObject(parent), m_type(0)
{

}

MyThread::~MyThread()
{
    qDebug("~MyThread()");
}

void MyThread::setType(const int &type)
{
    m_type = type;
}

void MyThread::run()
{
    switch (m_type) {
    case 0:
        thread1Worker();
        break;
    case 1:
        thread2Worker();
        break;
    case 2:
        thread3Worker();
        break;
    case 3:
        thread4Worker();
        break;
    default:
        break;
    }
}

QMutex mutex;

void MyThread::thread1Worker()
{
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    {
        mutex.lock();

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);
        db.setDatabaseName("ServerDSN");
        db.setUserName("SA");
        db.setPassword("DataSciec2019");
        if (!db.open())
        {
            qDebug() << "thread 1 open db failed!";
        }
        mutex.unlock();
        qDebug() << "thread 1: " << QThread::currentThreadId() << connectionName;
    }
    QSqlDatabase::removeDatabase(connectionName);
}

void MyThread::thread2Worker()
{
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    {
        mutex.lock();
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);
        db.setDatabaseName("ServerDSN");
        db.setUserName("SA");
        db.setPassword("DataSciec2019");
        if (!db.open())
        {
            qDebug() << "thread 2 open db failed!";
        }
        mutex.unlock();
        qDebug() << "thread 2: " << QThread::currentThreadId() << connectionName;
    }
    QSqlDatabase::removeDatabase(connectionName);
}

void MyThread::thread3Worker()
{
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    {
        mutex.lock();
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);
        db.setDatabaseName("ServerDSN");
        db.setUserName("SA");
        db.setPassword("DataSciec2019");
        if (!db.open())
        {
            qDebug() << "thread 3 open db failed!";
        }
        mutex.unlock();
        qDebug() << "thread 3: " << QThread::currentThreadId() << connectionName;
    }
    QSqlDatabase::removeDatabase(connectionName);
}

void MyThread::thread4Worker()
{
    QString connectionName = QString::number(*static_cast<int*>(QThread::currentThreadId()));
    {
        mutex.lock();
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);
        db.setDatabaseName("ServerDSN");
        db.setUserName("SA");
        db.setPassword("DataSciec2019");
        if (!db.open())
        {
            qDebug() << "thread 4 open db failed!";
        }
        mutex.unlock();
        qDebug() << "thread 4: " << QThread::currentThreadId() << connectionName;
    }

    QSqlDatabase::removeDatabase(connectionName);


}

