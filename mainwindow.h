#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>
#include <QSharedPointer>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    void closeEvent(QCloseEvent* event);
private:
    static void doDeleteLater(QLabel *label);
//    QSharedPointer<QLabel> label;
    std::shared_ptr<QLabel> label;
};
#endif // MAINWINDOW_H
