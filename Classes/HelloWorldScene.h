/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public Scene, public TableViewDataSource, public TableViewDelegate {
public:
    static Scene *createScene();

    bool init() override;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void tableCellTouched(TableView *table, TableViewCell *cell) override;

    Size tableCellSizeForIndex(TableView *table, ssize_t idx) override;

    TableViewCell *tableCellAtIndex(TableView *table, ssize_t idx) override;

    ssize_t numberOfCellsInTableView(TableView *table) override;;
private:
    // function
    void testTableView();

    // 测试腾讯的JSON
    void testRapidJson();
};

#endif // __HELLOWORLD_SCENE_H__
