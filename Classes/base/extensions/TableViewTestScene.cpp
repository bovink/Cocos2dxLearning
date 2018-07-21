//
// Created by 吴宗刚 on 2018/7/21.
//

#include "TableViewTestScene.h"
#include "TableItemView.h"

bool TableViewTestScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto tableView = TableView::create(this, _contentSize);
    tableView->setDirection(extension::
                            ScrollView::Direction::VERTICAL);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    tableView->setDelegate(this);
    tableView->setPosition(Vec2::ZERO);
    addChild(tableView);
    tableView->reloadData();

    return true;
}

// DataSource
Size TableViewTestScene::tableCellSizeForIndex(TableView *table, ssize_t idx) {
    return Size(180, 180);
}

Size TableViewTestScene::cellSizeForTable(TableView *table) {
    return TableViewDataSource::cellSizeForTable(table);
}

TableViewCell *TableViewTestScene::tableCellAtIndex(TableView *table, ssize_t idx) {

    auto item = ((TableItemView *) table->dequeueCell());

    if (item == nullptr) {

        item = TableItemView::newInstance(idx);

    } else {

        item->update(idx);
    }
    return item;
}

ssize_t TableViewTestScene::numberOfCellsInTableView(TableView *table) {
    return 20;
}

// Delegate
void TableViewTestScene::tableCellTouched(TableView *table, TableViewCell *cell) {

    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
}

void TableViewTestScene::tableCellHighlight(TableView *table, TableViewCell *cell) {
    TableViewDelegate::tableCellHighlight(table, cell);
}

void TableViewTestScene::tableCellUnhighlight(TableView *table, TableViewCell *cell) {
    TableViewDelegate::tableCellUnhighlight(table, cell);
}

void TableViewTestScene::tableCellWillRecycle(TableView *table, TableViewCell *cell) {
    TableViewDelegate::tableCellWillRecycle(table, cell);
}
