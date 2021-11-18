#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

#include "ConnectDb.h"


class MyThread : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    ~MyThread();
    void setType(const int &type);
protected:
    void run();
private:
    void thread1Worker();
    void thread2Worker();
    void thread3Worker();
    void thread4Worker();
private:
    int m_type;
};

#endif // MYTHREAD_H
