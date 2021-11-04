#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    void run() override;
private:
    QMutex mutex;
signals:
    void displayMsg(const QString& s);

};

#endif // MYTHREAD_H
