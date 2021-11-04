#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QSharedPointer>

#include "Classes/ConnectDb.h"
#include "Classes/send.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const int getCountMsg();

private:
    Ui::MainWindow *ui;
    ConnectDb *m_connect;
    QThread thread_1;
    QThread thread_2;

    Send *m_Send1;
    Send *m_Send2;

    int m_countMsg;    
signals:

private slots:
    void on_sendButton_clicked();
    void on_clearButton_clicked();
    void on_exitButton_clicked();

};
#endif // MAINWINDOW_H
