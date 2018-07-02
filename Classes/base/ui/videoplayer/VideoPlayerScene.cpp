//
// Created by bovink on 2018/6/4.
//

#include "VideoPlayerScene.h"
#include "cocos/ui/UIButton.h"

using namespace ui;

bool TestVideoPlayer::init() {
    if (!Scene::init()) {
        return false;
    }

    auto _videoPlayer = VideoPlayer::create();
    _videoPlayer->setName("video");
    _videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _videoPlayer->setPosition(Vec2(getContentSize().width / 2, getContentSize().height / 2));
    _videoPlayer->setContentSize(getContentSize() / 2);
    addChild(_videoPlayer);

    _videoPlayer->setFileName("video/cocosvideo.mp4");

//    _videoPlayer->setURL("http://benchmark.cocos2d-x.org/cocosvideo.mp4");

    _videoPlayer->play();
//    _videoPlayer->seekTo(10);

    // 将会在videoplayer的上方显示
    auto layer = LayerColor::create(Color4B(192, 0, 0, 255), getContentSize().width,
                                    getContentSize().height);
    layer->setPosition(Vec2(getContentSize().width / 2, getContentSize().height / 2));
    addChild(layer, 10);

    auto button = Button::create("animationbuttonnormal.png");
    button->setAnchorPoint(Vec2::ZERO);
    button->setPosition(Vec2::ZERO);
    button->addClickEventListener(CC_CALLBACK_1(TestVideoPlayer::onButtonClick, this));
    addChild(button);

    scheduleUpdate();
    return true;
}

void TestVideoPlayer::onButtonClick(Ref *ref) {

    VideoPlayer *videoPlayer = dynamic_cast<VideoPlayer *>(getChildByName("video"));
//    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity", "changedActivityOrientation", 1);
    int duration = videoPlayer->getDuration();

    CCLOG("duration = %d", duration);
}

void TestVideoPlayer::update(float delta) {

    VideoPlayer *videoPlayer = dynamic_cast<VideoPlayer *>(getChildByName("video"));
    int currentPosition = videoPlayer->getCurrentPosition();

    CCLOG("currentPosition = %d", currentPosition);
}
