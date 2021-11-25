#ifndef SENDINGTHREAD_H
#define SENDINGTHREAD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include <QSqlQuery>
#include <QMutex>

class SendingThread : public QObject
{
    Q_OBJECT
public:
    explicit SendingThread(const QString &connectionName);
    ~SendingThread();
signals:
    void query_result(const QString &result);
    void get_rows_result(const QString &count);
public slots:
    void send_query(const QString &msg, const QString &hash);
    void getRowsDatabase();
private:
    QSqlDatabase m_database;
};

#endif // SENDINGTHREAD_H
