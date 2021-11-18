#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QSharedPointer>

#include "Classes/ConnectDb.h"
#include "Classes/mythread.h"
#include "Classes/mythread2.h"

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
    QThread th1;
    QThread th2;

    MyThread2 *m_thread1;
    MyThread2 *m_thread2;
public slots:
    void start();
private slots:
    void on_sendButton_clicked();
    void on_clearButton_clicked();
    void on_exitButton_clicked();

};
#endif // MAINWINDOW_H
