//
// Created by bovink on 2018/6/4.
//

#include "TestVideoPlayer.h"

bool TestVideoPlayer::init() {
    if (!Scene::init()) {
        return false;
    }

    auto _videoPlayer = VideoPlayer::create();
    _videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _videoPlayer->setPosition(Vec2(getContentSize().width / 2, getContentSize().height / 2));
    _videoPlayer->setContentSize(getContentSize());
    addChild(_videoPlayer);

//    _videoPlayer->setFileName("video/cocosvideo.mp4");

    _videoPlayer->setURL("http://benchmark.cocos2d-x.org/cocosvideo.mp4");

    _videoPlayer->play();
    return true;
}
