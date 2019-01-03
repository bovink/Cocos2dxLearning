//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_TESTBUTTONSCENE_H
#define PROJ_ANDROID_TESTBUTTONSCENE_H

#include "BaseScene.h"

class ButtonScene : public BaseScene {

public:

    bool init() override;

    CREATE_FUNC(ButtonScene)
};

class TestClipScene : public BaseScene {

public:

    CREATE_FUNC(TestClipScene)

    bool init() override;

};

class TestListView : public BaseScene {

public:

    CREATE_FUNC(TestListView)

    bool init() override;

    int index = 0;
    ListView *listView;

};

class SizeTest : public BaseScene {

public:

    CREATE_FUNC(SizeTest)

    bool init() override;

};

class MarqueeTextTest : public BaseScene {

public:

    CREATE_FUNC(MarqueeTextTest)

    bool init() override;

    void printSomething();
};

#include "network/CCDownloader.h"
#include "DownloadModule.h"

class DownloadTestScene : public BaseScene {

public:

    CREATE_FUNC(DownloadTestScene)

    bool init() override;


private:

};

#include "DatabaseModule.h"

#include "sqlite3.h"

class StartScene : public BaseScene {

public:

    CREATE_FUNC(StartScene)

    bool init() override;

    // 模拟从服务器获取的数据
    void initFakeNetworkData();

    // 根据服务器获取的数据更新本地数据
    void updateLocalData(DownloadInfo downloadInfo);

    void checkDownloadResource(DownloadInfo info, int downloadState = -1);

    void createTable(sqlite3* pDb);

private:

    vector<DownloadInfo> downloadList;
};


#endif //PROJ_ANDROID_TESTBUTTONSCENE_H
