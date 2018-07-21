//
// Created by 吴宗刚 on 2018/7/21.
//

#ifndef PROJ_ANDROID_TABLEVIEWTESTSCENE_H
#define PROJ_ANDROID_TABLEVIEWTESTSCENE_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;

class TableViewTestScene : public Scene, public TableViewDataSource, public TableViewDelegate {

public:

    bool init() override;

    Size tableCellSizeForIndex(TableView *table, ssize_t idx) override;

    Size cellSizeForTable(TableView *table) override;

    TableViewCell *tableCellAtIndex(TableView *table, ssize_t idx) override;

    ssize_t numberOfCellsInTableView(TableView *table) override;

    void tableCellTouched(TableView *table, TableViewCell *cell) override;

    void tableCellHighlight(TableView *table, TableViewCell *cell) override;

    void tableCellUnhighlight(TableView *table, TableViewCell *cell) override;

    void tableCellWillRecycle(TableView *table, TableViewCell *cell) override;

    CREATE_FUNC(TableViewTestScene)

private:

};


#endif //PROJ_ANDROID_TABLEVIEWTESTSCENE_H
