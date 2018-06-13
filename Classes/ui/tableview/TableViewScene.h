//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_TESTTABLEVIEW_H
#define PROJ_ANDROID_TESTTABLEVIEW_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TestTableView : public Scene, public TableViewDataSource, public TableViewDelegate {
public:
    bool init() override;

    void tableCellTouched(TableView *table, TableViewCell *cell) override;

    TableViewCell *tableCellAtIndex(TableView *table, ssize_t idx) override;

    ssize_t numberOfCellsInTableView(TableView *table) override;

    CREATE_FUNC(TestTableView)

    Size cellSizeForTable(TableView *table) override;

};


#endif //PROJ_ANDROID_TESTTABLEVIEW_H
