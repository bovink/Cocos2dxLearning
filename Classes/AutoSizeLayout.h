//
// Created by 吴宗刚 on 2018/7/16.
//

#ifndef PROJ_ANDROID_AUTOSIZELAYOUT_H
#define PROJ_ANDROID_AUTOSIZELAYOUT_H


#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

namespace myStore {

    class AutoSizeLayout : public Layout
    {
    public:
        //CREATE_FUNC(AutoSizeLayout);
        AutoSizeLayout(Type loType) : Layout()
        {
            init();
            setLayoutType(loType);
        };

        virtual bool init() override;

        // I don't understand why but in C++ when you override one prototype, it hides all other prototypes of the same method !
        //	=> so override all prototypes the same way
        virtual void addChild(Node* child)override;
        virtual void addChild(Node * child, int localZOrder)override;
        virtual void addChild(Node* child, int localZOrder, int tag) override;
        virtual void addChild(Node* child, int localZOrder, const string &name) override;

        void setBackGroundFrame(string frame);

    protected:
        Size _childrenTotalSize;
        Size _backGroundSize;

        void ResizeFromChildAdded(Node* child);
        void updateContentSize();
    };

}


#endif //PROJ_ANDROID_AUTOSIZELAYOUT_H
