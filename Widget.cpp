#include "Widget.h"
#include <QDebug>
#include <QLabel>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    /*

    QMap<QString, QStringList> map{
        {"结构建模",{"定子和转子","绕组"}},
        {"初始化",{"运动区域","边界"}},
        {"分析方案",{"求解设置","激励","分析结果","参数化"}},
    };

    TreeItem* root = model->root();
    foreach(const QString &key, map.keys()) {
        TreeItem* keyItem = new TreeItem(key);
        root->addChild(keyItem);

        foreach(const QString &value, map.value(key)){
            TreeItem* valueItem = new TreeItem(value);
            keyItem->addChild(valueItem);
        }
    };

*/
    treeView = new TreeView(this);
    stackedLayout = new QStackedLayout();
    //centerWidget = new QLabel("center", this);
    stackedWidget = new QStackedWidget(this);
    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(treeView);
    //mainLayout->addLayout(stackedLayout);
    //mainLayout->addWidget(centerWidget);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(new QLabel("test", this), 1, Qt::AlignCenter);

    //centerWidget->setVisible(false);
    stackedWidget->setVisible(false);
    //stackedWidget->setCurrentWidget(nullptr);
    stackedWidget->addWidget(new QLabel("empty", this));
    stackedWidget->addWidget(new QLabel("container"));
    stackedWidget->addWidget(new QLabel("data"));

    model = new TreeModel(this);
    model->addProjectItem(new TreeItem("结构建模"))
            ->addChild(new TreeItem("定子和转子"))
            ->parent()->addChild(new TreeItem("绕组"))

            ->parent()->parent()->addChild(new TreeItem("初始化"))
            ->addChild(new TreeItem("运动区域"))
            ->parent()->addChild(new TreeItem("边界"))

            ->parent()->parent()->addChild(new TreeItem("分析方案"))
            ->addChild(new TreeItem("求解设置"))
            ->parent()->addChild(new TreeItem("激励"))
            ->parent()->addChild(new TreeItem("分析结果", nullptr, TreeItem::DATA))
            ->parent()->addChild(new TreeItem("参数化"));

    treeView->setModel(model);
    treeView->expandAll();

    connect(treeView, &QAbstractItemView::clicked, [&](const QModelIndex &index){
        if (index.isValid())
        {
            TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
            qDebug()<<item->getType();
            switch (item->getType()) {
            case TreeItem::EMPTY:
                //stackedLayout->setCurrentWidget(nullptr);
                stackedWidget->setVisible(false);
                break;
            case TreeItem::CONTAINER:
                //stackedLayout->setCurrentWidget(nullptr);
                //centerWidget->setVisible(false);
                stackedWidget->setVisible(false);
                break;
            case TreeItem::DATA:
                //centerWidget = new QLabel("data", this);
                //centerWidget->setVisible(true);
                //stackedLayout->setCurrentWidget(new QLabel("data", this));
                stackedWidget->setCurrentIndex(0);
                stackedWidget->setVisible(true);
                break;
            }
        }
    });
}
