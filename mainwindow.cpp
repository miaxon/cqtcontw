#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ls_menu->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->ls_menu->horizontalHeader()->setStretchLastSection(true);
    this->move(QApplication::desktop()->screen()->rect().center()-this->rect().center());
    ui->ls_menu->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotMenuClick(QModelIndex index){
    ContainerWindow::createWindow(model.getWidget(index))->show();
}


