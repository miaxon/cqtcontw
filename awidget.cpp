#include "awidget.h"
#include "ui_awidget.h"

AWidget::AWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AWidget)
{
    ui->setupUi(this);
}

AWidget::~AWidget()
{
    delete ui;
}
