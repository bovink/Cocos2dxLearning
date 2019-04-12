//
// Created by 吴宗刚 on 2018/6/13.
//

#include "ButtonScene.h"
#include "cocos/ui/CocosGUI.h"
#include <thread>
#include <iostream>
#include "md5.h"
#include "AudioEngine.h"

using namespace ui;

using namespace experimental;

bool ButtonScene::init() {

    if (!Scene::init()) {
        return false;
    }
    float _contentSizeWidth = getContentSize().width;
    float _contentSizeHeight = getContentSize().height;

    auto content = Layout::create();
    content->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    content->setBackGroundColor(Color3B::WHITE);
    content->setContentSize(_contentSize);
    addChild(content);

    auto button = Button::create("ps_jsu_anniu7.png", "ps_jsu_anniu7.png");
    button->setPosition(Vec2(_contentSizeWidth / 2, _contentSizeHeight / 2));

    // 点击事件
    button->addClickEventListener([](Ref *ref) {

        CCLOG("click button");
    });

    // 触摸事件
    button->addTouchEventListener([](Ref *ref, Widget::TouchEventType type) {
        Button *clickButton;
        clickButton = dynamic_cast<Button *>(ref);
        switch (type) {
            case Widget::TouchEventType::BEGAN:
                clickButton->setOpacity(50);
                CCLOG("touch begin");
                break;
            case Widget::TouchEventType::MOVED:
                CCLOG("touch moved");
                break;
            case Widget::TouchEventType::ENDED:
                clickButton->setOpacity(255);
                CCLOG("touch ended");
                break;
            case Widget::TouchEventType::CANCELED:
                clickButton->setOpacity(255);
                CCLOG("touch canceled");
                break;
        }
    });

    addChild(button);

    return true;
}

bool TestClipScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto renderer = _director->getRenderer();
    auto &parentTransform = _director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    auto sprite = ImageView::create("ps_danci_k1.png");
    sprite->setPosition(_contentSize / 2);

    auto cutSprite = ImageView::create("testbg.png");
    cutSprite->setScale9Enabled(true);
    cutSprite->setContentSize(_contentSize);
    cutSprite->setPosition(_contentSize / 2);

    auto _texture = RenderTexture::create(_contentSize.width,
                                          _contentSize.height,
                                          Texture2D::PixelFormat::RGBA8888);
    _texture->retain();
    _texture->setPosition(_contentSize / 2);
    addChild(_texture);

    _texture->begin();
    cutSprite->visit(renderer, parentTransform, true);
    _texture->end();

    BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
    sprite->setBlendFunc(func0);

    _texture->begin();
    sprite->visit(renderer, parentTransform, true);
    _texture->end();


    return true;
}

bool TestListView::init() {
    if (!BaseScene::init()) {
        return false;
    }

    listView = ListView::create();
    listView->setBounceEnabled(true);
    listView->setDirection(ScrollView::Direction::HORIZONTAL);
    listView->setContentSize(Size(_contentSize.width, 300));
//    listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
//    listView->setPosition(Vec2(_contentSize.width/2,0));
    listView->setPosition(Vec2::ZERO);

    addChild(listView);

    for (int i = 0; i < 4; ++i) {

        auto image = ImageView::create("testbg.png");
        image->setScale9Enabled(true);
        image->setContentSize(Size(200, 250));
        image->setTag(i);
        listView->pushBackCustomItem(image);
    }
    listView->setItemsMargin(40);
    listView->setLeftPadding(640 / 2 - 100);
    listView->setRightPadding(640 / 2 - 100);
    schedule([&](float dt) {

        __CCLOGWITHFUNCTION("%d", index);
        listView->scrollToItem(index, Vec2::ANCHOR_MIDDLE, Vec2::ANCHOR_MIDDLE);
        Widget *item;
        for (int i = 0; i < listView->getItems().size(); ++i) {

            item = listView->getItem(i);
            item->runAction(ScaleTo::create(1, 1));
        }
        item = listView->getItem(index);
        item->runAction(ScaleTo::create(1, 1.1));
        index++;
        if (index > 3) {
            index = 0;
        }
    }, 2, "a");

    return true;
}

bool SizeTest::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto root = Layout::create();
    root->setLayoutType(Layout::Type::VERTICAL);
    root->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    root->setBackGroundColor(Color3B::WHITE);
    root->setContentSize(_contentSize);
    root->setPosition(Vec2::ZERO);
    addChild(root);

    auto image1 = ImageView::create("testsize.png");
    auto image1P = LinearLayoutParameter::create();
    image1P->setMargin(Margin(0, 10, 0, 0));
    image1P->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    image1->setLayoutParameter(image1P);
    root->addChild(image1);

    auto image2 = ImageView::create("testsize.png");
    auto image2P = LinearLayoutParameter::create();
    image2P->setMargin(Margin(0, 10, 0, 0));
    image2P->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    image2->setLayoutParameter(image2P);
    root->addChild(image2);

    auto englishText1 = Text::create("abcdefghijklmnopqrstuvwxyz", "fonts/Roboto-Regular.ttf", 14);
    englishText1->setTextColor(Color4B::BLACK);
    auto englishText1P = LinearLayoutParameter::create();
    englishText1P->setMargin(Margin(0, 10, 0, 0));
    englishText1P->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    englishText1->setLayoutParameter(englishText1P);
    root->addChild(englishText1);

    auto englishText2 = Text::create("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "fonts/Roboto-Regular.ttf", 14);
    englishText2->setTextColor(Color4B::BLACK);
    auto englishText2P = LinearLayoutParameter::create();
    englishText2P->setMargin(Margin(0, 10, 0, 0));
    englishText2P->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    englishText2->setLayoutParameter(englishText2P);
    root->addChild(englishText2);

    auto numtext = Text::create("0123456789", "fonts/FZHTK.TTF", 14);
    numtext->setTextColor(Color4B::BLACK);
    auto numtextP = LinearLayoutParameter::create();
    numtextP->setMargin(Margin(0, 10, 0, 0));
    numtextP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    numtext->setLayoutParameter(numtextP);
    root->addChild(numtext);

    auto madarinText = Text::create("玉美松泉", "fonts/FZHTK.TTF", 14);
    madarinText->setTextColor(Color4B::BLACK);
    auto madarinTextP = LinearLayoutParameter::create();
    madarinTextP->setMargin(Margin(0, 10, 0, 0));
    madarinTextP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    madarinText->setLayoutParameter(madarinTextP);
    root->addChild(madarinText);

    return true;
}

bool MarqueeTextTest::init() {
    if (!BaseScene::init()) {
        return false;
    }

    auto root = Layout::create();
    root->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    root->setBackGroundColor(Color3B::WHITE);
    root->setContentSize(Size(200, 40));
    root->setPosition(Vec2(0, _contentSize.height / 2));
    addChild(root);

    auto node = DrawNode::create();
    node->drawSolidRect(Vec2(0, 0), Vec2(200, 40), Color4F::WHITE);

    auto clipNode = ClippingNode::create();
    clipNode->setStencil(node);
    clipNode->setPosition(Vec2(0, 0));
    root->addChild(clipNode);


    auto text = Text::create();
    text->setAnchorPoint(Vec2(0, 0));
    text->setString("vaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    text->setFontSize(20);
    text->setTextColor(Color4B::RED);
    text->setPosition(Vec2(0, 0));

    auto moveBy = MoveBy::create(5, Vec2(-50, 0));
//    text->runAction(RepeatForever::create(Sequence::create(moveBy, moveBy->reverse(), nullptr)));

    clipNode->addChild(text);

    auto btn = Button::create();
    btn->setTitleText("press the button");
    btn->setPosition(_contentSize / 2);
    btn->addClickEventListener([&](Ref *ref) {

        std::thread t = std::thread(&MarqueeTextTest::printSomething, this);
        t.detach();
        __CCLOGWITHFUNCTION("end");

    });

    addChild(btn);

    return true;
}


void MarqueeTextTest::printSomething() {

    for (int i = 0; i < 10; ++i) {

//        std::cout << i << std::endl;

        __CCLOGWITHFUNCTION("%d", i);

        std::chrono::milliseconds duration(1000);
        std::this_thread::sleep_for(duration);
    }
}

static const char *urlChar[] = {
        "http://img.daimg.com/uploads/allimg/120302/3-1203021T03E04.jpg",
        "http://video.dolphinmedia.cn/ef073948b5ba44d4b9691f2d9820b38b/08ac918f73e8434380388a8e664dbadf-5cc937797266cd387c1d7b65162819dd-ld.mp4"};


static const char *sNameList[] = {"1.jpg", "2.mp4"};

bool DownloadTestScene::init() {
    if (!BaseScene::init()) {
        return false;
    }

    __CCLOGWITHFUNCTION("DownloadTestScene");

    // 下载按钮
    auto button = Button::create("ps_jsu_anniu7.png", "ps_jsu_anniu7.png");
    button->setPosition(_contentSize / 2);
    button->addClickEventListener([&](Ref *ref) {
        string fileName = sNameList[0];
        string storagePath = FileUtils::getInstance()->getWritablePath() + "Download/";
        string downloadPath = urlChar[0];
        string MD5 = "";
        int resourceVersion = 100;
        int resourceID = 1;
        string des = "下载测试描述";
        DownloadInfo downloadInfo = DownloadInfo(storagePath, downloadPath, MD5, resourceVersion,
                                                 resourceID, des, fileName);
        DownloadService::getInstance()->startDownloadTask(downloadInfo);

        __CCLOGWITHFUNCTION("create download task");
    });
    addChild(button);

    auto path = FileUtils::getInstance()->getWritablePath();
    std::vector<std::string> files;
    FileUtils::getInstance()->listFilesRecursively(path, &files);
    __CCLOGWITHFUNCTION("xxxxxxxxxxxxxxxxxxxx");
    for (int i = 0; i < files.size(); ++i) {

        __CCLOGWITHFUNCTION("%s", files.at(i).c_str());
    }
    __CCLOGWITHFUNCTION("xxxxxxxxxxxxxxxxxxxx");

    return true;
}

bool StartScene::init() {
    if (!BaseScene::init()) {
        return false;
    }


    auto root = Layout::create();
    root->setLayoutType(Layout::Type::VERTICAL);
    root->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    root->setBackGroundColor(Color3B::WHITE);
    root->setContentSize(_contentSize);
    root->setPosition(Vec2::ZERO);
    addChild(root);


    auto img1 = ImageView::create();
    img1->setName("img1");
    img1->ignoreContentAdaptWithSize(false);
    img1->setContentSize(Size(200, 100));
    img1->setPosition(Vec2(_contentSize.width / 2, 100));
    addChild(img1);


    auto text = Text::create("点击按钮观看视频", "FZLTXIHK_1.TTF", 26);
    text->setColor(Color3B::BLACK);
    auto textP = LinearLayoutParameter::create();
    textP->setMargin(Margin(0, 50, 0, 0));
    textP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    text->setLayoutParameter(textP);
    root->addChild(text);

    auto createDatabaseBtn = Button::create("animationbuttonnormal.png",
                                            "animationbuttonpressed.png");
    createDatabaseBtn->setTitleText("下载图片");
    auto createDatabaseBtnP = LinearLayoutParameter::create();
    createDatabaseBtnP->setMargin(Margin(0, 50, 0, 0));
    createDatabaseBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    createDatabaseBtn->setLayoutParameter(createDatabaseBtnP);
    createDatabaseBtn->addClickEventListener([&](Ref *ref) {

        initFakeNetworkData();
    });
    root->addChild(createDatabaseBtn);

    auto createTableBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    createTableBtn->setTitleText("显示图片");
    auto createTableBtnP = LinearLayoutParameter::create();
    createTableBtnP->setMargin(Margin(0, 50, 0, 0));
    createTableBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    createTableBtn->setLayoutParameter(createTableBtnP);
    createTableBtn->addClickEventListener([&](Ref *ref) {

    });
    root->addChild(createTableBtn);

    auto insertBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    insertBtn->setTitleText("插入数据");
    auto insertBtnP = LinearLayoutParameter::create();
    insertBtnP->setMargin(Margin(0, 50, 0, 0));
    insertBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    insertBtn->setLayoutParameter(insertBtnP);
    insertBtn->addClickEventListener([&](Ref *ref) {

        __CCLOGWITHFUNCTION("====================");
        __CCLOGWITHFUNCTION("测试测试测试");
        __CCLOGWITHFUNCTION("====================");
    });
    root->addChild(insertBtn);

    auto queryBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    queryBtn->setTitleText("查询数据");
    auto queryBtnP = LinearLayoutParameter::create();
    queryBtnP->setMargin(Margin(0, 50, 0, 0));
    queryBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    queryBtn->setLayoutParameter(queryBtnP);
    queryBtn->addClickEventListener([&](Ref *ref) {

        string fileName = FileUtils::getInstance()->getWritablePath() + "Download/1.jpg";
        string fileMd5 = md5file(fileName.c_str());
        __CCLOGWITHFUNCTION("filemd5:%s", fileMd5.c_str());
    });
    root->addChild(queryBtn);

    auto deleteBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    deleteBtn->setTitleText("删除数据");
    auto deleteBtnP = LinearLayoutParameter::create();
    deleteBtnP->setMargin(Margin(0, 50, 0, 0));
    deleteBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    deleteBtn->setLayoutParameter(deleteBtnP);
    deleteBtn->addClickEventListener([&](Ref *ref) {

        ImageView *image1 = dynamic_cast<ImageView *>(getChildByName("img1"));
        image1->loadTexture(FileUtils::getInstance()->getWritablePath() + "Download/1.jpg");
    });
    root->addChild(deleteBtn);

    auto modifyBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    modifyBtn->setTitleText("修改数据");
    auto modifyBtnP = LinearLayoutParameter::create();
    modifyBtnP->setMargin(Margin(0, 50, 0, 0));
    modifyBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    modifyBtn->setLayoutParameter(modifyBtnP);
    modifyBtn->addClickEventListener([&](Ref *ref) {

        string sql = "SELECT * FROM resource";
        sqlite3 *pDb = NULL;
        DatabaseModule::getInstance()->openDatabase(&pDb, "resourceDb");
        DatabaseModule::getInstance()->queryData(pDb, sql);
    });
    root->addChild(modifyBtn);


    return true;
}

void StartScene::initFakeNetworkData() {
    // 数据1
    string fileName = sNameList[0];
    string storagePath = FileUtils::getInstance()->getWritablePath() + "Download/";
    string downloadPath = urlChar[0];
    string MD5 = "5cd3cc12262abb569f79cfc6dbb25bee";
    int resourceVersion = 101;
    int resourceID = 1;
    string des = "图片1";
    DownloadInfo info1 = DownloadInfo(storagePath, downloadPath, MD5, resourceVersion,
                                      resourceID, des, fileName);

    downloadList.push_back(info1);

    // 数据2
    fileName = sNameList[1];
    storagePath = FileUtils::getInstance()->getWritablePath() + "Download/";
    downloadPath = urlChar[1];
    MD5 = "";
    resourceVersion = 102;
    resourceID = 2;
    des = "图片2";
    DownloadInfo info2 = DownloadInfo(storagePath, downloadPath, MD5, resourceVersion,
                                      resourceID, des, fileName);

    downloadList.push_back(info2);
    for (int i = 0; i < downloadList.size(); ++i) {
        DownloadInfo info = downloadList.at(i);

        updateLocalData(info);
    }

    DownloadService::getInstance()->setOnTaskSuccess(
            [&](const cocos2d::network::DownloadTask &task) {
                __CCLOGWITHFUNCTION("下载完成:%s", task.identifier.c_str());
                // 检查下载文件的md5值
                string selectSql = StringUtils::format(
                        "SELECT MD5 FROM resource WHERE downloadPath = '%s'",
                        task.requestURL.c_str());
                char **table;
                int r, c;
                sqlite3 *pDb = NULL;
                DatabaseModule::getInstance()->openDatabase(&pDb, "resourceDb");
                DatabaseModule::getInstance()->queryData2(pDb, selectSql, &table, &r, &c);

                // 必须释放查询表
                string originMD5 = table[r * c];
                __CCLOGWITHFUNCTION("查询md5为:%s", originMD5.c_str());
                string fileMd5 = md5file(task.storagePath.c_str());
                __CCLOGWITHFUNCTION("文件md5为:%s", fileMd5.c_str());
                sqlite3_free_table(table);
                // 对比md5
                if (fileMd5 == originMD5) {// MD5相同

                    string sql = StringUtils::format(
                            "UPDATE resource SET downloadState = 2 WHERE downloadPath = '%s'",
                            task.requestURL.c_str());

                    DatabaseModule::getInstance()->modifyData(pDb, sql);
                } else {
                    string sql = StringUtils::format(
                            "DELETE FROM resource WHERE downloadPath = '%s'",
                            task.requestURL.c_str());

                    DatabaseModule::getInstance()->deleteData(pDb, sql);
                }

            });

    DownloadService::getInstance()->setOnTaskError([&](const cocos2d::network::DownloadTask &task,
                                                       int errorCode,
                                                       int errorCodeInternal,
                                                       const std::string &errorStr) {
        __CCLOGWITHFUNCTION("下载异常");
        string sql = StringUtils::format(
                "UPDATE resource SET downloadState = 1 WHERE downloadPath = '%s'",
                task.requestURL.c_str());

        sqlite3 *pDb = NULL;
        DatabaseModule::getInstance()->openDatabase(&pDb, "resourceDb");
        DatabaseModule::getInstance()->modifyData(pDb, sql);
    });
}

void StartScene::updateLocalData(DownloadInfo downloadInfo) {

    sqlite3 *pDb = NULL;
    DatabaseModule::getInstance()->openDatabase(&pDb, "resourceDb");
    // 检查表是否存在，不存在则创建表
    if (!DatabaseModule::getInstance()->checkTableExist(pDb, "resource")) {

        createTable(pDb);
    }


    // 根据resourceId搜索数据是否存在，不存在则插入数据，状态为-1
    string selectSql = StringUtils::format(
            "SELECT resourceVersion, downloadState FROM resource WHERE resourceID = %d",
            downloadInfo.getResourceID());

    char **table;
    int r, c;
    DatabaseModule::getInstance()->queryData2(pDb, selectSql, &table, &r, &c);
    if (r == 0 && c == 0) {
        // 数据不存在，直接插入数据
        insertData(pDb, downloadInfo);

        // 下载数据
        checkDownloadResource(pDb, downloadInfo);
        __CCLOGWITHFUNCTION("插入数据");
    } else {
        // 数据存在，对比资源版本，如果新数据的resourceVersion要大，则覆盖数据，状态为-1

        int resourceVersion = stoi(table[r * c]);
        if (downloadInfo.getResourceVersion() > resourceVersion) {
            __CCLOGWITHFUNCTION("修改数据");
            // 修改数据
            updateData(pDb, downloadInfo);
            // 下载数据
            checkDownloadResource(pDb, downloadInfo);
            // 同时更新数据的下载状态
        } else {
            // 根据本地数据的状态来决定是否下载
            int downloadState = stoi(table[r * c + 1]);
            __CCLOGWITHFUNCTION("是否下载:%d", downloadState);
            checkDownloadResource(pDb, downloadInfo, downloadState);
            // 同时更新数据的下载状态

        }

    }

    // 必须释放查询表
    sqlite3_free_table(table);


}

void StartScene::checkDownloadResource(sqlite3 *pDb, DownloadInfo info, int downloadState) {
    // 当资源处于未下载或者暂停下载时则开始下载数据
    if (downloadState != 0 && downloadState != 2) {

        DownloadService::getInstance()->startDownloadTask(info);

        updateDownloadState(pDb, 0, info.getResourceID());
    }
}

void StartScene::createTable(sqlite3 *pDb) {

    string sql = "create table resource(ID integer primary key autoincrement, storagePath text, downloadPath text, MD5 text, resourceVersion integer, "
            "resourceID integer, des text, fileName text, downloadState integer)";
    DatabaseModule::getInstance()->createTable(pDb, sql);
}

void StartScene::insertData(sqlite3 *pDb, DownloadInfo info) {

    string insertSql = StringUtils::format(
            "INSERT INTO resource (storagePath, downloadPath, MD5, resourceVersion, resourceID, des, fileName, downloadState) "
                    "VALUES ('%s', "
                    "'%s', "
                    "'%s', "
                    "%d, "
                    "%d, "
                    "'%s', "
                    "'%s', "
                    "%d)", info.getStoragePath().c_str(), info.getDownloadPath().c_str(),
            info.getMD5().c_str(),
            info.getResourceVersion(), info.getResourceID(), info.getDes().c_str(),
            info.getFileName().c_str(),
            info.getDownloadState());
    DatabaseModule::getInstance()->insertData(pDb, insertSql);
}

void StartScene::updateData(sqlite3 *pDb, DownloadInfo info) {

    string updateSql = StringUtils::format("UPDATE resource SET "
                                                   "storagePath = '%s', "
                                                   "downloadPath = '%s', "
                                                   "MD5 = '%s', "
                                                   "resourceVersion = %d, "
                                                   "des = '%s', "
                                                   "fileName = '%s', "
                                                   "downloadState = %d "
                                                   "WHERE resourceID = %d",
                                           info.getStoragePath().c_str(),
                                           info.getDownloadPath().c_str(), info.getMD5().c_str(),
                                           info.getResourceVersion(), info.getDes().c_str(),
                                           info.getFileName().c_str(), info.getDownloadState(),
                                           info.getResourceID());

    DatabaseModule::getInstance()->modifyData(pDb, updateSql);
}

void StartScene::updateDownloadState(sqlite3 *pDb, int downloadState, int resourceID) {


    string sql = StringUtils::format("UPDATE resource SET downloadState = %d WHERE resourceID = %d",
                                     downloadState, resourceID);

    DatabaseModule::getInstance()->modifyData(pDb, sql);
}

void StartScene::setAllTaskPaused() {
    DownloadService::getInstance()->stopAllTasks();
    string sql = "UPDATE resource SET downloadState = 1 WHERE downloadState = 0";

    sqlite3 *pDb = NULL;
    DatabaseModule::getInstance()->openDatabase(&pDb, "resourceDb");
    DatabaseModule::getInstance()->modifyData(pDb, sql);
}

StartScene::~StartScene() {
    setAllTaskPaused();
}

///////////////////////////////////测试点9图///////////////////////////////////

Scale9Test::Scale9Test() {

}

Scale9Test::~Scale9Test() {

}

bool Scale9Test::init() {
    if (!BaseScene::init()) {
        return false;
    }

    bg = ImageView::create("ps_tinglibj.png");
    bg->setPosition(_contentSize / 2);
    bg->setScale9Enabled(true);
    bg->setCapInsets(Rect(0, 0, 640, 100));
    addChild(bg);

    auto btn1 = Button::create("animationbuttonnormal.png");
    btn1->addClickEventListener([&](Ref *ref) {
        bg->setContentSize(Size(bg->getContentSize().width, bg->getContentSize().height + 5));
    });
    btn1->setPosition(Vec2(50, 50));
    btn1->setTitleText("增加高度");
    addChild(btn1);

    auto btn2 = Button::create("animationbuttonnormal.png");
    btn2->addClickEventListener([&](Ref *ref) {

        bg->setContentSize(Size(bg->getContentSize().width, bg->getContentSize().height - 5));
    });
    btn2->setPosition(Vec2(_contentSize.width - 50, 50));
    btn2->setTitleText("减少高度");
    addChild(btn2);


    return true;
}

//

SliceImageTest::SliceImageTest() {

}

SliceImageTest::~SliceImageTest() {

}

bool SliceImageTest::init() {
    if (!BaseScene::init()) {
        return false;
    }
    auto root = Layout::create();
    root->setLayoutType(Layout::Type::RELATIVE);
    root->setContentSize(_contentSize);
    root->setPosition(Vec2::ZERO);
    addChild(root);
//
//    auto background = ImageView::create("dolphin/background.png");
//    background->setScale9Enabled(true);
//    background->setContentSize(_contentSize);
//    auto backgroundP = RelativeLayoutParameter::create();
//    backgroundP->setAlign(RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT);
//    background->setLayoutParameter(backgroundP);
//    root->addChild(background);
//
    auto bg = ImageView::create("dolphin/cover1.png");
    bg->setContentSize(Size(bg->getContentSize().width - 1, bg->getContentSize().height - 1));
    auto bgP = RelativeLayoutParameter::create();
    bgP->setAlign(RelativeLayoutParameter::RelativeAlign::CENTER_IN_PARENT);
    bg->setLayoutParameter(bgP);
//    root->addChild(bg);

    auto video = VideoPlayer::create();
    video->setContentSize(bg->getContentSize());
    video->setFileName("dolphin/video1.mp4");
    root->addChild(video);
    auto videoP = RelativeLayoutParameter::create();
    videoP->setMargin(Margin(_contentSize.width / 2 - bg->getContentSize().width / 2, 300, 0, 0));
    videoP->setAlign(RelativeLayoutParameter::RelativeAlign::PARENT_TOP_LEFT);
    video->setLayoutParameter(videoP);
    video->play();

    auto renderer = _director->getRenderer();
    auto &parentTransform = _director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    // 背景，需要被裁剪
    auto background = ImageView::create("dolphin/background.png");
    background->setScale9Enabled(true);
    background->setContentSize(_contentSize);
    background->setPosition(_contentSize / 2);

    // 裁剪背景
    auto cut = ImageView::create("dolphin/cover1.png");
    cut->setScale(0.99f);
    cut->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    cut->setPosition(Size(_contentSize.width / 2, _contentSize.height - 300));
    BlendFunc func0 = {GL_ZERO, GL_ONE_MINUS_SRC_ALPHA};
    cut->setBlendFunc(func0);

    // 画板
    auto canvas = RenderTexture::create(_contentSize.width,
                                        _contentSize.height,
                                        Texture2D::PixelFormat::RGBA8888);
    canvas->setPosition(_contentSize / 2);

    canvas->begin();
    background->visit(renderer, parentTransform, true);
    cut->visit(renderer, parentTransform, true);
    canvas->end();
    addChild(canvas);
    background->setVisible(false);
    cut->setVisible(false);
//    canvas->setVisible(false);
    return true;
}

MotionStreakTest::MotionStreakTest() {

}

MotionStreakTest::~MotionStreakTest() {

}

bool MotionStreakTest::init() {
    if (!BaseScene::init()) {

        return false;
    }
    __CCLOGWITHFUNCTION("%s", __FUNCTION__);
    auto eventListenerTouchOneByOne = EventListenerTouchOneByOne::create();

    eventListenerTouchOneByOne->onTouchBegan = CC_CALLBACK_2(MotionStreakTest::onTouchBegan, this);

    eventListenerTouchOneByOne->onTouchMoved = CC_CALLBACK_2(MotionStreakTest::onTouchMoved, this);

    eventListenerTouchOneByOne->onTouchEnded = CC_CALLBACK_2(MotionStreakTest::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListenerTouchOneByOne, this);

    image = ImageView::create("ps_fj_sjcgg_tt38.png");
    image->setPosition(Vec2(0, _contentSize.height / 2));
    image->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    addChild(image);

    schedule([&](float) {
        image->setPosition(Vec2(random(-200, 0), 0));

        ccBezierConfig bezierConfig;


        bezierConfig.controlPoint_1 = Vec2(0, _contentSize.height);
        bezierConfig.controlPoint_2 = Vec2(_contentSize.width - 200, _contentSize.height);
        bezierConfig.endPosition = Vec2(_contentSize.width + random(-200, 0), -300);
        auto bezierTo = BezierTo::create(3, bezierConfig);
        auto delayTime = DelayTime::create(1);

        auto seq = Sequence::create(bezierTo, delayTime, NULL);
        image->runAction(seq);

        // 旋转动画
        auto rotate = random(90, 180);
        auto rotateBy = RotateBy::create(3, rotate);
        auto ease = EaseOut::create(rotateBy, 2.5);
        image->runAction(ease);
    }, 5, "run_action");

    return true;
}

bool MotionStreakTest::onTouchBegan(Touch *touch, Event *event) {
    auto streak = MotionStreak::create(0.5, 3, 5, Color3B::WHITE, "streak.png");
    streak->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    addChild(streak);
    streakList.push_back(streak);
    currentIndex = streakList.size() - 1;
    JniHelper::callStaticVoidMethod("org/cocos2dx/cpp/AppActivity",
                                    "testSomething");
    return true;
}

void MotionStreakTest::onTouchMoved(Touch *touch, Event *event) {

    MotionStreak *node = streakList.at(currentIndex);
    node->setPosition(touch->getLocation());
    auto x = checkTouch(Rect(image->getPosition(), image->getContentSize()),
                        Rect(touch->getLocation(), node->getContentSize()));
    if (x) {
        __CCLOGWITHFUNCTION("碰撞");
        AudioEngine::play2d("audio/good.mp3");
    } else {

        __CCLOGWITHFUNCTION("无碰撞");
    }
}

void MotionStreakTest::onTouchEnded(Touch *touch, Event *event) {

    if (streakList.size() > 10) {
        for (int i = 0; i < streakList.size(); ++i) {
            removeChild(streakList.at(i));
        }

        streakList.clear();
    }
}

bool MotionStreakTest::checkTouch(Rect rect1, Rect rect2) {
    float x1 = rect1.origin.x;//矩形1中心点的横坐标
    float y1 = rect1.origin.y;//矩形1中心点的纵坐标
    float w1 = rect1.size.width;//矩形1的宽度
    float h1 = rect1.size.height;//矩形1的高度
    float x2 = rect2.origin.x;
    float y2 = rect2.origin.y;
    float w2 = rect2.size.width;
    float h2 = rect2.size.height;

    if (x1 + w1 * 0.5 < x2 - w2 * 0.5)
        return false;//矩形1在矩形2左方，两者无碰撞
    else if (x1 - w1 * 0.5 > x2 + w2 * 0.5)
        return false;//矩形1在矩形2右方，两者无碰撞
    else if (y1 + h1 * 0.5 < y2 - h2 * 0.5)
        return false;//矩形1在矩形2下方，两者无碰撞
    else if (y1 - h1 * 0.5 > y2 + h2 * 0.5)
        return false;//矩形1在矩形2上方，两者无碰撞

    return true;
}
