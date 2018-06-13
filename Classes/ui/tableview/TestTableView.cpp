//
// Created by 吴宗刚 on 2018/6/13.
//

#include "TestTableView.h"
#include "CustomViewCell.h"

bool TestTableView::init() {
    if (!Scene::init()) {
        return false;
    }

    // vertical
//    auto tableView = TableView::create(this, Size(120, getContentSize().height));
//    tableView->setDirection(ScrollView::Direction::VERTICAL);
//    tableView->setPosition(Vec2((getContentSize().width - 120) / 2, 0));
//    tableView->setDelegate(this);
//    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
//    this->addChild(tableView);
//    tableView->reloadData();

    // horizontal
    auto tableView = TableView::create(this, Size(getContentSize().width, 120));
    tableView->setDirection(ScrollView::Direction::HORIZONTAL);
    tableView->setPosition(Vec2(0, (getContentSize().height - 120) / 2));
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();

    return true;
}

void TestTableView::tableCellTouched(TableView *table, TableViewCell *cell) {

    CCLOG("touch index %d", cell->getIdx());

}

TableViewCell *TestTableView::tableCellAtIndex(TableView *table, ssize_t idx) {
    auto cell = table->dequeueCell();
    if (!cell) {

        cell = new(std::nothrow) CustomViewCell(idx);
        cell->autorelease();
    } else {

        ((CustomViewCell *) cell)->updateCell(idx);
    }

    return cell;
}

ssize_t TestTableView::numberOfCellsInTableView(TableView *table) {
    return 20;
}

Size TestTableView::cellSizeForTable(TableView *table) {
    return Size(120, 120);
}
