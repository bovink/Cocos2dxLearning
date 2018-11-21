//
// Created by bovink on 2018/6/4.
//

#include "VideoPlayerScene.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool TestVideoPlayer::init() {
    if (!BaseScene::init()) {
        return false;
    }

    // 设置场景
    CCLOG("scene pos:%f,%f", getPositionX(), getPositionY());
    setContentSize(Size(1280, 720));

    auto _videoPlayer = VideoPlayer::create();
    _videoPlayer->setName(_NAME_VIDEO);
    _videoPlayer->setContentSize(getContentSize());
    _videoPlayer->setPosition(Vec2(640, 360 + 560));
    addChild(_videoPlayer);


    _videoPlayer->setFileName("video/cocosvideo.mp4");

    _videoPlayer->play();

    auto button = Button::create("animationbuttonnormal.png","animationbuttonpressed.png");
    button->setPosition(Vec2(640, 360));
    addChild(button);

    auto image = ImageView::create("grossini_dance_08.png");
    image->setPosition(Vec2(640, 360));
    addChild(image);
//    scheduleUpdate();
    return true;
}

void TestVideoPlayer::update(float delta) {
    VideoPlayer *_videoPlayer = dynamic_cast<VideoPlayer *>(getChildByName(_NAME_VIDEO));
    float duration = _videoPlayer->getDuration();
    CCLOG("duration:%d",duration);
}
