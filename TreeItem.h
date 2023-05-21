#pragma once

#include <QVariant>
#include <QSharedPointer>

#include "BaseData.h"

class TreeItem
{
public:
    enum Type
    {
        EMPTY = 0,
        CONTAINER,
        DATA
    };

    explicit TreeItem(const QString &name = "", TreeItem *parent = nullptr, Type type = EMPTY);
    ~TreeItem();

    TreeItem *parent() const { return _parent; }
    void setParent(TreeItem *parent){_parent = parent;}

    int childCount() const { return _children.count(); }
    TreeItem *child(int row) { return _children.value(row); }

    TreeItem *addChild(TreeItem *item);
    void removeChildren();

    QVariant data(int role) const;

    Type getType() const { return _type; }
    void setType(const Type &value) { _type = value; }

    void setData(const QSharedPointer<BaseData> &data) { _data = data; }
    QSharedPointer<BaseData> getData() const { return _data; }

    void setRow(int row) { _row = row; }
    int row() const { return _row; }

private:
    QString _name;
    TreeItem *_parent;
    QList<TreeItem*> _children;
    Type _type;
    QSharedPointer<BaseData> _data;
    int _row;
};
