#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QStackedWidget>

#include "TreeView.h"
#include "TreeModel.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
private:
    TreeView *treeView;
    TreeModel* model;

    QStackedLayout *stackedLayout;
    QWidget *centerWidget;
    QStackedWidget *stackedWidget;
    QHBoxLayout *mainLayout;
};
