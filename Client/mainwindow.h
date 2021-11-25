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
private slots:
    void on_actionExit_triggered();
private:
    Ui::MainWindow *ui;
    QThread th1;
    QThread th2;
    ConnectDb *m_thread1;
public slots:
    void start();
};
#endif // MAINWINDOW_H
