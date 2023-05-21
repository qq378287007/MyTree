#include "TreeModel.h"
#include "TreeItem.h"

TreeModel::TreeModel( QObject *parent)
    : QAbstractItemModel(parent)
{
    _rootItem = new TreeItem();
}

TreeModel::~TreeModel()
{
    delete _rootItem;
}

TreeItem *TreeModel::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid())
    {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        return item;
    }
    return _rootItem;
}

TreeItem *TreeModel::root()
{
    return _rootItem;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid()){
        TreeItem *item = itemFromIndex(index);
        return item->data(role);
    }
    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(hasIndex(row, column, parent))
    {
        TreeItem *parentItem = itemFromIndex(parent);
        TreeItem *item = parentItem->child(row);
        if (item)
            return createIndex(row, column, item);
    }
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *item = itemFromIndex(index);
    TreeItem *parentItem = item->parent();

    if (parentItem == _rootItem)
        return QModelIndex();
    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    TreeItem* item = itemFromIndex(parent);
    return item->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}
