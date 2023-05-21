#pragma once

#include <QTreeView>

class TreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit TreeView(QWidget *parent = nullptr);
};
