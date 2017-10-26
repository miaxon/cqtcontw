#include "menumodel.h"

MenuModel::MenuModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    menu[0] = MENUITEM("AWidget", ACTION<AWidget>);
    menu[1] = MENUITEM("BWidget", ACTION<BWidget>);
}

QVariant MenuModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
            switch (section) {
            case 0:
                return tr("Action");
            default:
                return QVariant();
            }
        }
        if (orientation == Qt::Vertical && role == Qt::DisplayRole) {
            return section + 1;
        }
        return QVariant();
}

int MenuModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return menu.count();
}

int MenuModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 1;
}

QVariant MenuModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()|| index.row() >= menu.count())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
       return menu.find(index.row()).value().first;
    }
    return QVariant();
}
QWidget* MenuModel::getWidget(const QModelIndex &index)
{
    if (!index.isValid())
        return new QWidget();
    return (menu.find(index.row()).value().second)();
}
