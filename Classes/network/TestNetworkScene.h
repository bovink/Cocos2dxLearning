//
// Created by bovink on 2018/6/5.
//

#ifndef PROJ_ANDROID_TESTNETWORK_H
#define PROJ_ANDROID_TESTNETWORK_H

#include "BaseScene.h"
#include "GoHttp.h"
#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

class TestNetworkScene : public BaseScene {
public:
    bool init() override;

    CREATE_FUNC(TestNetworkScene);

private:

    void testNetworkGet();

    //Http Response Callback
    void onHttpRequestCompleted(cocos2d::network::HttpClient *sender,
                                cocos2d::network::HttpResponse *response);

    Sprite *imageView;
    GoHttp *goHttp;
};


#endif //PROJ_ANDROID_TESTNETWORK_H
