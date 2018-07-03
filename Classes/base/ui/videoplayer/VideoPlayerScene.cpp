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
    _videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _videoPlayer->setPosition(Vec2(640, 360 + 600 - 40));
    addChild(_videoPlayer);

    _videoPlayer->setFileName("video/cocosvideo.mp4");

    _videoPlayer->play();

    return true;
}

