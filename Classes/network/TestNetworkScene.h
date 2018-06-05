//
// Created by bovink on 2018/6/5.
//

#ifndef PROJ_ANDROID_TESTNETWORK_H
#define PROJ_ANDROID_TESTNETWORK_H

#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

class TestNetworkScene : public Scene {
public:
    bool init() override;

    CREATE_FUNC(TestNetworkScene);

private:

    void testNetworkGet();

};


#endif //PROJ_ANDROID_TESTNETWORK_H
