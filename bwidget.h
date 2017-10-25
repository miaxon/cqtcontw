#ifndef BWIDGET_H
#define BWIDGET_H

#include "awidget.h"

namespace Ui {
class BWidget;
}

class BWidget : public AWidget
{
    Q_OBJECT

public:
    explicit BWidget(QWidget *parent = 0);
    ~BWidget();
    static QWidget* getInstance()
    {
        return new BWidget();
    }

private:
    Ui::BWidget *ui;
};

#endif // BWIDGET_H
