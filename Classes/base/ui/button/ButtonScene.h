//
// Created by 吴宗刚 on 2018/6/13.
//

#ifndef PROJ_ANDROID_TESTBUTTONSCENE_H
#define PROJ_ANDROID_TESTBUTTONSCENE_H

#include "BaseScene.h"
#include "FairyGUI.h"


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

    ~StartScene();

    bool init() override;

    // 模拟从服务器获取的数据
    void initFakeNetworkData();

    // 根据服务器获取的数据更新本地数据
    void updateLocalData(DownloadInfo downloadInfo);

    void checkDownloadResource(sqlite3 *pDb, DownloadInfo info, int downloadState = -1);

    void createTable(sqlite3 *pDb);

    void insertData(sqlite3 *pDb, DownloadInfo info);

    void updateData(sqlite3 *pDb, DownloadInfo info);

    void updateDownloadState(sqlite3 *pDb, int downloadState, int resourceID);

    void setAllTaskPaused();

private:

    vector<DownloadInfo> downloadList;
};

class Scale9Test : public BaseScene {

public:

    CREATE_FUNC(Scale9Test)

    Scale9Test();

    ~Scale9Test();

    bool init() override;

private:

    ImageView *bg;
};

class SliceImageTest : public BaseScene {

public:

    CREATE_FUNC(SliceImageTest)

    SliceImageTest();

    ~SliceImageTest();

    bool init() override;
};

class MotionStreakTest : public BaseScene {

public:

    CREATE_FUNC(MotionStreakTest)

    MotionStreakTest();

    ~MotionStreakTest();

    bool init() override;

    virtual bool onTouchBegan(Touch *touch, Event *event);

    virtual void onTouchMoved(Touch *touch, Event *event);

    virtual void onTouchEnded(Touch *touch, Event *event);

    bool checkTouch(Rect rect1, Rect rect2);

private:
    ImageView *image;
    vector<MotionStreak *> streakList;
    int currentIndex;
};

class FairyGUITest : public BaseScene {

public:

    CREATE_FUNC(FairyGUITest);

    FairyGUITest();

    ~FairyGUITest();

    bool init() override;

private:

    fairygui::GRoot* groot;
};

#endif //PROJ_ANDROID_TESTBUTTONSCENE_H
