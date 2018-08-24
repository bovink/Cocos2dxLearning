//
// Created by 吴宗刚 on 2018/6/12.
//

#include "TextScene.h"

bool TextScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    auto richText = RichText::create();
    richText->ignoreContentAdaptWithSize(false);
    richText->setContentSize(Size(_contentSize.width, 200));

    auto re = RichElementText::create(1, Color3B::BLACK, 255, "看图学单词，\n点击话筒还可以跟读哦！\n单词数量：6",
                                      "FZLTXIHK_1.TTF", 38);
    richText->pushBackElement(re);
    richText->setHorizontalAlignment(RichText::HorizontalAlignment::CENTER);
    richText->setPosition(_contentSize / 2);
    addChild(richText);

    auto text2 = Text::create("看图学单词，\n点击话筒还可以跟读哦！\n单词数量：6",
                              "FZLTXIHK_1.TTF", 38);
    text2->setTextColor(Color4B::BLACK);
    text2->setPosition(Size(_contentSize.width / 2, _contentSize.height / 2 - 100));
    text2->setTextHorizontalAlignment(TextHAlignment::CENTER);
    addChild(text2);
    return true;
}
