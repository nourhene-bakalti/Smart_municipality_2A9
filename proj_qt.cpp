#include "proj_qt.h"

proj_qt::proj_qt(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant proj_qt::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex proj_qt::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex proj_qt::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int proj_qt::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int proj_qt::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant proj_qt::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
