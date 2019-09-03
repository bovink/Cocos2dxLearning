/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    initListView();
    initListData();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::initListView() {

    auto _layoutItem = generateLayout();

    ListView *listView = ListView::create();
    listView->setName(_NAME_LIST);
    listView->setDirection(ui::ScrollView::Direction::VERTICAL);
    listView->setContentSize(Size(_contentSize.width, _contentSize.height - 48));
    listView->setPosition(Vec2::ZERO);
    addChild(listView);

    listView->setItemModel(_layoutItem);
}

void HelloWorld::initListData() {

    ListView *listView = dynamic_cast<ListView *>(getChildByName(_NAME_LIST));

    std::vector<const std::string> titles;
    titles.push_back("长腿爸爸");
    titles.push_back("月亮之歌");
    titles.push_back("爱哭的猫头鹰");
    titles.push_back("蔬菜大家族");
    titles.push_back("抱抱我");
    titles.push_back("飘着幽灵的小房子");
    titles.push_back("红气球不见了");
    titles.push_back("两个怪物");
    titles.push_back("我会刷牙了");
    titles.push_back("海盗兔子小分队");
    titles.push_back("萝卜不见了");

    for (int i = 0; i < titles.size(); i++) {
        string title = titles.at(i);

        Widget *item = generateLayout();
        item->setTouchEnabled(true);
        item->addClickEventListener(CC_CALLBACK_1(HelloWorld::onItemClickEvent, this));
        item->setTag(i);
        Text *titleText = dynamic_cast<Text *>(item->getChildByName(_NAME_TITLE));
        titleText->setString(title);
        listView->pushBackCustomItem(item);
    }

    listView->setItemsMargin(20);
}

Layout *HelloWorld::generateLayout() {

    auto *text = Text::create("example", "", 80);
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

void HelloWorld::onItemClickEvent(Ref *ref) {
    Layout *layout = dynamic_cast<Layout *>(ref);
    int tag = layout->getTag();

}
