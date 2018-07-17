//
// Created by 吴宗刚 on 2018/7/16.
//

#include "DrawNodeScene.h"
#include "cocos/ui/UIImageView.h"

using namespace ui;

bool DrawNodeScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto helloWorld = ImageView::create("HelloWorld.png");
    helloWorld->setPosition(_contentSize / 2);
    addChild(helloWorld);

    Rect r = helloWorld->getBoundingBox();


    auto line = DrawNode::create();
    line->drawSolidRoundedRect(Vec2(r.getMinX() - 20, r.getMinY() - 20),
                               Vec2(r.getMaxX() + 20, r.getMaxY() + 20), 20,
                               10000, Color4F::WHITE);
    line->setPosition(0, 0);
    addChild(line);


    return true;
}
