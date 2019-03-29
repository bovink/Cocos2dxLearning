//
// Created by 吴宗刚 on 2018/6/14.
//

#include "ListViewScene.h"
#include "UserDefaultScene.h"
#include "TextScene.h"
#include "JniScene.h"
#include "MainScene.h"
#include "ScrollViewScene.h"
#include "DrawNodeScene.h"
#include "TestNetworkScene.h"
#include "TableViewTestScene.h"
#include "TabControlScene.h"
#include "VideoPlayerScene.h"
#include "EraserScene.h"
#include "ImageViewScene.h"
#include "ButtonScene.h"

using namespace std;

static void executeCheckOrderStatus(int width, int height);

static int mheight = 0;

static int screenWidth = 0;
static int screenHeight = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

extern "C" {
void
Java_org_cocos2dx_cpp_AppActivity_changeSize(JNIEnv *env, jobject obj, jint width, jint height) {
    executeCheckOrderStatus(width, height);
}
}
#endif

void executeCheckOrderStatus(int width, int height) {
    mheight = height;
    screenWidth = width;
    screenHeight = height;

    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("test");
}

bool MainScene::init() {
    if (!Scene::init()) {

        return false;
    }

    initListView();

    initListData();

    auto checkListener = EventListenerCustom::create("test",
                                                     [&](EventCustom *e) {

//                                                         int height = reinterpret_cast<int>(e->getUserData());
                                                         CCLOG("HEIGHT:%d", mheight);
                                                         auto glView = _director->getOpenGLView();
                                                         auto frameSize = glView->getFrameSize();
                                                         glView->setFrameSize(screenWidth,
                                                                              screenHeight);
                                                         glView->setDesignResolutionSize(
                                                                 glView->getDesignResolutionSize().width,
                                                                 glView->getDesignResolutionSize().height,
                                                                 ResolutionPolicy::FIXED_WIDTH);
                                                     });

    _eventDispatcher->addEventListenerWithFixedPriority(checkListener, 1);
    return true;
}

void MainScene::initListView() {

    auto _layoutItem = generateLayout();

    ListView *listView = ListView::create();
    listView->setName(_NAME_LIST);
    listView->setDirection(ui::ScrollView::Direction::VERTICAL);
    listView->setContentSize(Size(_contentSize.width, _contentSize.height - 48));
    listView->setPosition(Vec2::ZERO);
    addChild(listView);

    listView->setItemModel(_layoutItem);
}

void MainScene::initListData() {

    ListView *listView = dynamic_cast<ListView *>(getChildByName(_NAME_LIST));

    std::vector<const std::string> titles;
    titles.push_back("listview");
    titles.push_back("User Default");
    titles.push_back("JNI");
    titles.push_back("ScrollView");
    titles.push_back("Draw Node");

    titles.push_back("Network");
    titles.push_back("TableView");
    titles.push_back("TextTest");
    titles.push_back("TabControl");
    titles.push_back("Video");

    titles.push_back("eraser");
    titles.push_back("FrameAnimation");
    titles.push_back("ButtonScene");
    titles.push_back("TestClipScene");
    titles.push_back("TestListView");

    titles.push_back("SizeTest");
    titles.push_back("MarqueeText");
    titles.push_back("DownloadTest");
    titles.push_back("StartScene");
    titles.push_back("Scale9 Test Scene");
    titles.push_back("SliceImage");
    titles.push_back("MotionStreak");

    for (int i = 0; i < titles.size(); i++) {
        string title = titles.at(i);

        Widget *item = generateLayout();
        item->setTouchEnabled(true);
        item->addClickEventListener(CC_CALLBACK_1(MainScene::onItemClickEvent, this));
        item->setTag(i);
        Text *titleText = dynamic_cast<Text *>(item->getChildByName(_NAME_TITLE));
        titleText->setString(title);
        listView->pushBackCustomItem(item);
    }

    listView->setItemsMargin(20);
}

Layout *MainScene::generateLayout() {

    auto *text = Text::create("example", "fonts/arial.ttf", 80);
    text->setName(_NAME_TITLE);

    auto params = LinearLayoutParameter::create();
    params->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    text->setLayoutParameter(params);

    auto _layoutItem = Layout::create();
    _layoutItem->setLayoutType(Layout::Type::VERTICAL);
    _layoutItem->setPosition(Vec2::ZERO);
    _layoutItem->setContentSize(Size(_contentSize.width, text->getContentSize().height));
    _layoutItem->addChild(text);

    return _layoutItem;
}

void MainScene::onItemClickEvent(Ref *ref) {
    Layout *layout = dynamic_cast<Layout *>(ref);
    int tag = layout->getTag();

    Scene *scene;
    switch (tag) {
        case 0:
            scene = ListViewScene::create();
            _director->pushScene(scene);
            break;
        case 1:
            scene = UserDefaultScene::create();
            _director->pushScene(scene);
            break;
        case 2:
            scene = JniScene::create();
            _director->pushScene(scene);
            break;
        case 3:
            scene = ScrollViewScene::create();
            _director->pushScene(scene);
            break;
        case 4:
            scene = DrawNodeScene::create();
            _director->pushScene(scene);
            break;
        case 5:
            scene = TestNetworkScene::create();
            _director->pushScene(scene);
            break;
        case 6:
            scene = TableViewTestScene::create();
            _director->pushScene(scene);
            break;
        case 7:
            scene = TextScene::create();
            _director->pushScene(scene);
            break;
        case 8:
            scene = TabControlScene::create();
            _director->pushScene(scene);
            break;
        case 9:
            scene = TestVideoPlayer::create();
            _director->pushScene(scene);
            break;
        case 10:
            scene = EraserScene2::create();
            _director->pushScene(scene);
            break;
        case 11:
            scene = TestFrameAnimation::create();
            _director->pushScene(scene);
            break;
        case 12:
            scene = ButtonScene::create();
            _director->pushScene(scene);
            break;
        case 13:
            scene = TestClipScene::create();
            _director->pushScene(scene);
            break;
        case 14:
            scene = TestListView::create();
            _director->pushScene(scene);
            break;
        case 15:
            scene = SizeTest::create();
            _director->pushScene(scene);
            break;
        case 16:
            scene = MarqueeTextTest::create();
            _director->pushScene(scene);
            break;
        case 17:
            scene = DownloadTestScene::create();
            _director->pushScene(scene);
            break;
        case 18:
            scene = StartScene::create();
            _director->pushScene(scene);
            break;
        case 19:
            scene = Scale9Test::create();
            _director->pushScene(scene);
            break;
        case 20:
            scene = SliceImageTest::create();
            _director->pushScene(scene);
            break;
        case 21:
            scene = MotionStreakTest::create();
            _director->pushScene(scene);
            break;
        default:
            break;
    }
}



