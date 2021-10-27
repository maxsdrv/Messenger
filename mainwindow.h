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

//    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    ConnectDb *m_connect;

};
#endif // MAINWINDOW_H
