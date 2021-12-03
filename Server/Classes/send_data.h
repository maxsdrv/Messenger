#ifndef SENDDATA_H
#define SENDDATA_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QThread>
#include <QSqlQuery>
#include <QMutex>

class SendData : public QObject
{
    Q_OBJECT
public:
    explicit SendData(const QString &connectionName);
    ~SendData();
signals:
    void query_result(const QString &result);
    void get_rows_result(const QString &count);
public slots:
    void send_query(const QString &msg, const QString &hash);
    void getRowsDatabase();
private:
    QSqlDatabase m_database;
    mutable QMutex m_mutex;
};

#endif // SENDDATA_H
