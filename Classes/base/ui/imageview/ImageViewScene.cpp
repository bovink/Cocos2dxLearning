//
// Created by 吴宗刚 on 2018/6/12.
//

#include "ImageViewScene.h"

bool TestFrameAnimation::init() {
    if (!BaseScene::init()) {
        return false;
    }

    initViews();

    return true;
}

void TestFrameAnimation::initViews() {

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    // 播放动画的精灵
    auto sprite = Sprite::create("animation/ps_huanchong1.png");
    sprite->setPosition(_contentSize / 2);
    addChild(sprite);

    Vector<SpriteFrame *> frames;
    for (int i = 0; i < 9; ++i) {

        std::string name = StringUtils::format("animation/ps_huanchong%d.png", i + 1);
        auto s = Sprite::create(name);
        auto spriteFrame = s->getSpriteFrame();
        frames.pushBack(spriteFrame);
    }
    auto animation = Animation::createWithSpriteFrames(frames);
    animation->setDelayPerUnit(0.1);
    auto animate = Animate::create(animation);
    sprite->runAction(RepeatForever::create(animate));
}
