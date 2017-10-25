#include "menumodel.h"

MenuModel::MenuModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    registry.insert("AWidget", &AWidget::getInstance);
    registry.insert("BWidget", &BWidget::getInstance);
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

    return registry.count();
}

int MenuModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 1;
}

QVariant MenuModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()|| index.row() >= registry.count())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
       QMapIterator<QString, t_getInstance> it(registry);
       int i = 0;
       while(it.hasNext())
       {
           it.next();
           if(i == index.row())
                return  it.key();
           i++;
       }
    }
    return QVariant();
}
QWidget* MenuModel::getWidget(const QModelIndex &index)
{
    if (!index.isValid())
        return new QWidget();
    QMapIterator<QString, t_getInstance> it(registry);
    int i = 0;
    while(it.hasNext())
    {
        it.next();
        if(i == index.row())
             return (it.value())();
        i++;
    }
    return new QWidget();
}