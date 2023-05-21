#include <QHeaderView>
#include "TreeView.h"

TreeView::TreeView(QWidget *parent) : QTreeView(parent)
{
    setSelectionBehavior(QTreeView::SelectRows);			//一次选中整行
    setSelectionMode(QTreeView::SingleSelection);        //单选，配合上面的整行就是一次选单行
    setFocusPolicy(Qt::NoFocus);                         //去掉鼠标移到单元格上时的虚线框
    header()->setStretchLastSection(true);               //最后一列自适应宽度
    setHeaderHidden(true);
}
