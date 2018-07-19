//
// Created by 吴宗刚 on 2018/7/19.
//

#ifndef PROJ_ANDROID_GOHTTP_H
#define PROJ_ANDROID_GOHTTP_H


#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace network;

class GoHttp {

public:

    GoHttp *create();

    GoHttp *setUrl(const std::string &url);

    GoHttp *setRequestType(HttpRequest::Type type);

    GoHttp *setResponseCallback();

    GoHttp *setTag(const std::string &tag);

    void send();
private:

    //Http Response Callback
    void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);

private:
    HttpRequest *_hr;
};


#endif //PROJ_ANDROID_GOHTTP_H
