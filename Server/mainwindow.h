#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QCryptographicHash>

#include "Classes/send_data.h"
#include "Classes/get_data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    std::unique_ptr<QThread> th1;
    std::unique_ptr<QThread> th2;
    std::unique_ptr<SendData> m_thread1;
    std::unique_ptr<SendData> m_thread2;

    QString m_count_rows; //storing the numbers of rows;
private:
    void setCountRows(const QString &count);
    const QString &getCountRows() const;
signals:
    void query_result(const QString &result, const QString &count_rows);
public slots:
    void start();
private slots:
    void on_sendButton_clicked();
    void on_clearButton_clicked();
    void on_exitButton_clicked();

    void cleanup();
};
#endif // MAINWINDOW_H
