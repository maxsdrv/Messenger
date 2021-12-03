#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H

#include <QWidget>
#include <QThread>
#include <QTimer>

#include "Classes/get_data.h"

namespace Ui {
class Client;
}

class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();
private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_Clear_clicked();

    void cleanup();

    void start();
private:
    Ui::Client *ui;

    std::unique_ptr<QThread> m_thread1;
    std::unique_ptr<QThread> m_thread2;

    std::unique_ptr<GetData> m_get_data1;
    std::unique_ptr<GetData> m_get_data2;

    QString m_hash;
    QTimer m_timer;
    mutable QMutex m_mutex;
private:
    void connects_To_Database();
};

#endif // CLIENT_WINDOW_H
