#include "bwidget.h"
#include "ui_bwidget.h"

BWidget::BWidget(QWidget *parent) :
    AWidget(parent),
    ui(new Ui::BWidget)
{
    ui->setupUi(this);
}

BWidget::~BWidget()
{
    delete ui;
}
