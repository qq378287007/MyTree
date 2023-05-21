#pragma once

#include <QAbstractItemModel>

#include "TreeItem.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TreeModel(QObject *parent = nullptr);
    ~TreeModel();
    TreeItem *root();
    TreeItem *addProjectItem(TreeItem *item){
        _rootItem->addChild(item);
        return item;
    }
public:
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
private:
    TreeItem *itemFromIndex(const QModelIndex &index) const;
private:
    TreeItem* _rootItem;
};
