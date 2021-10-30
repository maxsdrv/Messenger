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

    const int getCountRow();

private slots:
    void on_actiongetMessage_triggered();

    void on_actionClear_triggered();

    void on_actiondeleteFromDatabase_triggered();

    void on_actionExit_triggered();

private:
    ConnectDb *m_connectDb;
    Ui::MainWindow *ui;
    int m_rowCount;
};
#endif // MAINWINDOW_H
