#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <QAbstractTableModel>
#include <QMainWindow>
#include "awidget.h"
#include "bwidget.h"

typedef QWidget* (*fncreate_t)();
#define REG_WIDGET(x) QPair<QString, fncreate_t>(#x, &MenuModel::createWidget<x>)

class MenuModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit MenuModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QWidget* getWidget(const QModelIndex &index);

private:
    QMap<int, QPair<QString, fncreate_t>> registry;

    template<typename T>
    static QWidget* createWidget(){
        return new T();
    }
};

#endif // MENUMODEL_H
