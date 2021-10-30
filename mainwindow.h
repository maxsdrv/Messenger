#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Classes/ConnectDb.h"

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
    int m_countMsg;
private slots:
    void on_sendButton_clicked();
    void on_cancelButton_clicked();
};
#endif // MAINWINDOW_H
