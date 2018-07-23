//
// Created by 吴宗刚 on 2018/6/12.
//

#include "TextScene.h"

bool TextScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto richText = RichText::create();
    richText->ignoreContentAdaptWithSize(false);
    richText->setContentSize(Size(_contentSize.width, 200));

    auto re = RichElementText::create(1, Color3B::WHITE, 255, "看图学单词，\n点击话筒还可以跟读哦！\n单词数量：6", "fonts/fangzheng.ttf", 30);

    richText->pushBackElement(re);
    richText->setHorizontalAlignment(RichText::HorizontalAlignment::CENTER);
    richText->setPosition(_contentSize / 2);
    addChild(richText);
    return true;
}
