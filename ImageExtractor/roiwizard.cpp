#include "roiwizard.h"

ROIWizard::ROIWizard(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant ROIWizard::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex ROIWizard::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex ROIWizard::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int ROIWizard::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ROIWizard::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ROIWizard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
