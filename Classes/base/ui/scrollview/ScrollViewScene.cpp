//
// Created by 吴宗刚 on 2018/7/16.
//

#include "ScrollViewScene.h"
#include "cocos/ui/UIScrollView.h"
#include "cocos/ui/UIImageView.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool ScrollViewScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto imageview = ImageView::create("ps_xz_ditu.png");

    // Create the scrollview by vertical
    auto scrollView = ui::ScrollView::create();
    scrollView->setPosition(Vec2::ZERO);
    scrollView->setContentSize(_contentSize);
    scrollView->setScrollBarWidth(4);
    scrollView->setScrollBarPositionFromCorner(Vec2(2, 2));
    scrollView->setScrollBarColor(Color3B::WHITE);
    scrollView->setGlobalZOrder(200);
    scrollView->setInnerContainerSize(imageview->getContentSize());
    addChild(scrollView);

    imageview->setPosition(scrollView->getInnerContainerSize() / 2);
    scrollView->addChild(imageview);


    return true;
}
