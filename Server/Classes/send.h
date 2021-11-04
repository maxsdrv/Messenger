#ifndef SEND_H
#define SEND_H

#include <QObject>
#include <QtCore>
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QSqlQuery>

#include "Classes/ConnectDb.h"


class Send : public QObject
{
    Q_OBJECT

private:
    QMutex mutex;
    int mCount;
    QString mMessage1;
    QString mMessage2;
    bool mStop;

    QSqlDatabase m_DataBase;
    ConnectDb *m_Connect;
public:
    explicit Send(QObject *parent = nullptr);
//    Send(QSqlDatabase database);
    ~Send();


//    bool running() const;
//    const QString &message() const;
//    const QString &message2() const;

public slots:
    void run();
    void setRunning(bool newRunning);
    void setMessage(const QString &newMessage);
    void setMessage2(const QString &newMessage2);
signals:
    void stopSignal();
    void sendMessage(const QString& msg);
//    void finished();
    void runningChanged(bool runing);
    void messageChanged();
    void message2Changed();
//    void sendMessage(const QString& msg);
};

#endif // SEND_H
