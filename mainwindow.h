#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include "menumodel.h"
#include "containerwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void slotMenuClick(QModelIndex index);
private:
    Ui::MainWindow *ui;

    MenuModel model;
};

#endif // MAINWINDOW_H
