#ifndef CONTAINERWINDOW_H
#define CONTAINERWINDOW_H

#include <QMainWindow>

namespace Ui {
class ContainerWindow;
}

class ContainerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContainerWindow(QWidget *parent = 0);
    ~ContainerWindow();
    static QMainWindow* createWindow(QWidget* content)
    {
        ContainerWindow* w = new ContainerWindow();
        w->setCentralWidget(content);
        return w;
    }

private:
    Ui::ContainerWindow *ui;
};

#endif // CONTAINERWINDOW_H
