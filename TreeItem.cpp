#include "TreeItem.h"

TreeItem::TreeItem(const QString &name, TreeItem *parent, Type type)
    : _name(name)
    ,_parent(parent)
    ,_type(type)
    , _row(-1)
{
}

TreeItem::~TreeItem()
{
    removeChildren();
}

TreeItem *TreeItem::addChild(TreeItem *item)
{
    item->setParent(this);
    item->setRow(_children.size());
    _children.append(item);
    return item;
}

void TreeItem::removeChildren()
{
    qDeleteAll(_children);
    _children.clear();
}

QVariant TreeItem::data(int role) const
{
    switch(role){
    case Qt::DisplayRole:
        return _name;
    default:
        return QVariant();
    }
}
