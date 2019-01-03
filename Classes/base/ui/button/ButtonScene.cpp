//
// Created by 吴宗刚 on 2018/6/13.
//

#include "ButtonScene.h"
#include "cocos/ui/CocosGUI.h"
#include <thread>
#include <iostream>

using namespace ui;

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

static const char *urlChar =
        "http://video.dolphinmedia.cn/ef073948b5ba44d4b9691f2d9820b38b/08ac918f73e8434380388a8e664dbadf-5cc937797266cd387c1d7b65162819dd-ld.mp4";

static const char *sNameList[] = {"1.mp4", "2.mp4", "3.mp4"};

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
        string downloadPath = urlChar;
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

    initFakeNetworkData();

    auto root = Layout::create();
    root->setLayoutType(Layout::Type::VERTICAL);
    root->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    root->setBackGroundColor(Color3B::WHITE);
    root->setContentSize(_contentSize);
    root->setPosition(Vec2::ZERO);
    addChild(root);

    auto text = Text::create("点击按钮观看视频", "FZLTXIHK_1.TTF", 26);
    text->setColor(Color3B::BLACK);
    auto textP = LinearLayoutParameter::create();
    textP->setMargin(Margin(0, 50, 0, 0));
    textP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    text->setLayoutParameter(textP);
    root->addChild(text);

    auto createDatabaseBtn = Button::create("animationbuttonnormal.png",
                                            "animationbuttonpressed.png");
    createDatabaseBtn->setTitleText("打开数据库");
    auto createDatabaseBtnP = LinearLayoutParameter::create();
    createDatabaseBtnP->setMargin(Margin(0, 50, 0, 0));
    createDatabaseBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    createDatabaseBtn->setLayoutParameter(createDatabaseBtnP);
    createDatabaseBtn->addClickEventListener([&](Ref *ref) {

        sqlite3 *pDb = NULL;
        DatabaseModule::getInstance()->openDatabase(&pDb, "database");
        if (DatabaseModule::getInstance()->checkTableExist(pDb, "testm")) {

            __CCLOGWITHFUNCTION("存在");
        } else {
            __CCLOGWITHFUNCTION("不存在");

        }
    });
    root->addChild(createDatabaseBtn);

    auto createTableBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    createTableBtn->setTitleText("创建表");
    auto createTableBtnP = LinearLayoutParameter::create();
    createTableBtnP->setMargin(Margin(0, 50, 0, 0));
    createTableBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    createTableBtn->setLayoutParameter(createTableBtnP);
    createTableBtn->addClickEventListener([&](Ref *ref) {

        sqlite3 *pDb = NULL;
        DatabaseModule::getInstance()->openDatabase(&pDb, "database");

        string sql = "create table testm(ID integer primary key autoincrement, name text, sex text)";
        DatabaseModule::getInstance()->createTable(pDb, sql);
    });
    root->addChild(createTableBtn);

    auto insertBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    insertBtn->setTitleText("插入数据");
    auto insertBtnP = LinearLayoutParameter::create();
    insertBtnP->setMargin(Margin(0, 50, 0, 0));
    insertBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    insertBtn->setLayoutParameter(insertBtnP);
    insertBtn->addClickEventListener([&](Ref *ref) {

    });
    root->addChild(insertBtn);

    auto queryBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    queryBtn->setTitleText("查询数据");
    auto queryBtnP = LinearLayoutParameter::create();
    queryBtnP->setMargin(Margin(0, 50, 0, 0));
    queryBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    queryBtn->setLayoutParameter(queryBtnP);
    queryBtn->addClickEventListener([&](Ref *ref) {

    });
    root->addChild(queryBtn);

    auto deleteBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    deleteBtn->setTitleText("删除数据");
    auto deleteBtnP = LinearLayoutParameter::create();
    deleteBtnP->setMargin(Margin(0, 50, 0, 0));
    deleteBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    deleteBtn->setLayoutParameter(deleteBtnP);
    deleteBtn->addClickEventListener([&](Ref *ref) {

    });
    root->addChild(deleteBtn);

    auto modifyBtn = Button::create("animationbuttonnormal.png", "animationbuttonpressed.png");
    modifyBtn->setTitleText("修改数据");
    auto modifyBtnP = LinearLayoutParameter::create();
    modifyBtnP->setMargin(Margin(0, 50, 0, 0));
    modifyBtnP->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    modifyBtn->setLayoutParameter(modifyBtnP);
    modifyBtn->addClickEventListener([&](Ref *ref) {

    });
    root->addChild(modifyBtn);


    return true;
}

void StartScene::initFakeNetworkData() {
    string fileName = sNameList[0];
    string storagePath = FileUtils::getInstance()->getWritablePath() + "Download/";
    string downloadPath = urlChar;
    string MD5 = "";
    int resourceVersion = 100;
    int resourceID = 3;
    string des = "下载测试描述";
    DownloadInfo downloadInfo = DownloadInfo(storagePath, downloadPath, MD5, resourceVersion,
                                             resourceID, des, fileName);
//    downloadList.push_back(downloadInfo);
    updateLocalData(downloadInfo);
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

    CCLOG("行数 is %d , 列数 is %d", r, c);

    // 第0行（0 ~ c-1），为字段名
    // 第1行（c ~ 2*c-1），第一条记录
    // ......
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j < c; j++) {
            CCLOG("%s", table[i * c + j]);
        }
        CCLOG("------------------------------");
    }

    // 必须释放查询表
    sqlite3_free_table(table);


    // 初始化本地私有变量

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
