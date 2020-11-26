#include "projet_qt.h"

projet_qt::projet_qt(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant projet_qt::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex projet_qt::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex projet_qt::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int projet_qt::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int projet_qt::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant projet_qt::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
