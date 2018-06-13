//
// Created by 吴宗刚 on 2018/6/13.
//

#include "AudioEngineScene.h"
#include "AudioEngine.h"

using namespace experimental;

bool AudioEngineScene::init() {
    if (!Scene::init()) {
        return false;
    }

    CCLOG("audio engine scene init");

    AudioEngine::play2d("audio/good.mp3");

    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = [](Touch *touch, Event *event) {

        AudioEngine::stopAll();
        return true;
    };

    listener->onTouchMoved = [](Touch *touch, Event *event) {

    };

    listener->onTouchEnded = [](Touch *touch, Event *event) {

        AudioEngine::play2d("audio/good.mp3");
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}
