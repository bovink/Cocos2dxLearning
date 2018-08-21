//
// Created by 吴宗刚 on 2018/8/21.
//

#include <recast/Detour/DetourMath.h>
#include "Toast.h"

bool Toast::init() {
    if (!Layout::init()) {
        return false;
    }

    initViews();
    return true;
}

void Toast::initViews() {
    Size frameSize = Director::getInstance()->getWinSize();
    setContentSize(frameSize);

    // 消息层
    auto messageLayout = Layout::create();
    messageLayout->setContentSize(frameSize);
    messageLayout->setPosition(Vec2::ZERO);
    addChild(messageLayout);

    // 黑色背景
    drawNode = DrawNode::create();
    drawNode->setOpacity(0);
    messageLayout->addChild(drawNode);

    auto layout = Layout::create();
    layout->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    layout->setPosition(_contentSize / 2);
    messageLayout->addChild(layout);

    text = Text::create(_message, "fonts/fangzheng.ttf", 30);
    text->setTextHorizontalAlignment(TextHAlignment::CENTER);
    text->setOpacity(0);
    // 消息宽
    float textSize = text->getContentSize().width + 100;
    // 最大宽
    float maxSize = frameSize.width * 0.7f;

    // 消息行数
    int line = static_cast<int>(textSize / maxSize < 1 ? 1 : dtMathCeilf(textSize / maxSize));
    if (line > 1) {

        text->ignoreContentAdaptWithSize(false);
        text->setContentSize(Size(frameSize.width * 0.7f, text->getContentSize().height * line));
    }
    layout->addChild(text);

    layout->setContentSize(
            Size(text->getContentSize().width + 100, text->getContentSize().height + 50));
    text->setPosition(layout->getContentSize() / 2);

    auto rect = layout->getBoundingBox();
    drawNode->drawSolidRoundedRect(Vec2(rect.getMinX(), rect.getMinY()),
                                   Vec2(rect.getMaxX(), rect.getMaxY()), 40, 10000,
                                   Color4F(0, 0, 0, 1));

    auto fadeIn = ActionFloat::create(0.5, 0, 255, [&](float value) {

        drawNode->setOpacity(value);
        text->setOpacity(value);
    });
    auto delay = DelayTime::create(1);
    auto fadeOut = ActionFloat::create(0.5, 255, 0, [&](float value) {

        drawNode->setOpacity(value);
        text->setOpacity(value);

    });
    auto remove = CallFunc::create([&]() { removeFromParent(); });
    auto seq = Sequence::create(fadeIn, delay, fadeOut, remove, nullptr);

    runAction(seq);

}

Toast *Toast::newInstance(string message) {
    Toast *node = new Toast();
    node->_message = message;
    if (node->init()) {
        node->autorelease();

        return node;
    } else {
        delete node;
        return nullptr;
    }
}
