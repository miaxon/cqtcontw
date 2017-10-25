#ifndef AWIDGET_H
#define AWIDGET_H

#include <QWidget>

namespace Ui {
class AWidget;
}

class AWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AWidget(QWidget *parent = 0);
    ~AWidget();
    static QWidget* getInstance()
    {
        return new AWidget();
    }

private:
    Ui::AWidget *ui;
};

#endif // AWIDGET_H
