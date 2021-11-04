#include "send.h"

Send::Send(QObject *parent) : QObject(parent), mMessage1(""),
                                               mMessage2(""),
                                               mCount(0)
{

}

//Send::Send(QSqlDatabase dataBase) : m_DataBase(std::move(dataBase))
//{
//    if (!m_DataBase.open()) {
//        qDebug() << "Error open database Send()";
//    }
//    else qDebug() << "Send() got database correct";
//}
Send::~Send()
{
    qDebug() << "~Send()";
}


void Send::run()
{   
    /*while (mStop) {
        mutex.lock();
        ++mCount;
        emit sendMessage(mMessage1);
        qDebug() << mMessage1 << " " << mMessage2 << mCount;
        QThread::msleep(500);
        mutex.unlock();
    }*/



    int countMsg = 0;


    QSqlQuery queryCount;
    queryCount.exec("select count (*) from UserMessages");
    if (queryCount.last()) {
        countMsg = queryCount.value(0).toInt();
    }
    qDebug() << mMessage1 << " " << countMsg << " " << mMessage2;



//    QSqlQuery queryCount;
//    queryCount.exec("select count (*) from UserMessages");
//    if (queryCount.last()) {
//        countMsg = queryCount.value(0).toInt();
//    }
//    QSqlQuery queryInto;
//    QString sQuery {"insert into UserMessages values (:id, :user_name, :text"};
//    queryInto.prepare(sQuery);
//    queryInto.bindValue(":id", countMsg + 1);
//    queryInto.bindValue(":user_name", "PC");
//    queryInto.bindValue(":text", mMessage1);

//    mutex.unlock();

//    mutex.lock();
//    QSqlQuery queryGetMsg;
//    queryGetMsg.exec("select * from UserMessages");
//    if (queryGetMsg.last()) {
//        qDebug() << queryGetMsg.value(2).toString();
//    }



    emit stopSignal();
}


/*bool Send::running() const
{
    return m_running;
}
*/
void Send::setRunning(bool newRunning)
{
    if (mStop == newRunning)
        return;
    mStop = newRunning;
    emit runningChanged(newRunning);
}
/*
const QString &Send::message() const
{
    return m_message;
}
*/
void Send::setMessage(const QString &newMessage)
{
    if (mMessage1 == newMessage)
        return;
    mMessage1 = newMessage;
    emit messageChanged();
}
/*
const QString &Send::message2() const
{
    return m_message2;
}
*/
void Send::setMessage2(const QString &newMessage2)
{
    if (mMessage2 == newMessage2)
        return;
    mMessage2 = newMessage2;
    emit message2Changed();
}
