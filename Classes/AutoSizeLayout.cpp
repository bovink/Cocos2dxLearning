//
// Created by 吴宗刚 on 2018/7/16.
//

#include "AutoSizeLayout.h"

namespace myStore {

    bool AutoSizeLayout::init()
    {
        bool ret = Layout::init();
        if (ret)
        {
            setAnchorPoint(Vec2::ANCHOR_MIDDLE);
            _childrenTotalSize = Size::ZERO;
            _backGroundSize = Size::ZERO;
        }
        return ret;
    }

    void AutoSizeLayout::addChild(Node *child, int zOrder, int tag)
    {
        // 1. Do the base work
        Layout::addChild(child, zOrder, tag);
        // 2. Do the auto size additionnal work
        ResizeFromChildAdded(child);
    }

    void AutoSizeLayout::addChild(Node* child)
    {
        // 1. Do the base work
        Layout::addChild(child);
        // 2. Do the auto size additionnal work
        ResizeFromChildAdded(child);
    }

    void AutoSizeLayout::addChild(Node * child, int localZOrder)
    {
        // 1. Do the base work
        Layout::addChild(child, localZOrder);
        // 2. Do the auto size additionnal work
        ResizeFromChildAdded(child);
    }

    void AutoSizeLayout::addChild(Node* child, int zOrder, const std::string &name)
    {
        // 1. Do the base work
        Layout::addChild(child, zOrder, name);
        // 2. Do the auto size additionnal work
        ResizeFromChildAdded(child);
    }

    void AutoSizeLayout::ResizeFromChildAdded(Node* child)
    {
        // OP : I don't understand why getLayoutAccumulatedSize returns the margin size * 0.5 !!
        // => so I can't use it for children total size !
        //Size s = getLayoutAccumulatedSize();

        const Size& childSize = child->getContentSize();
        CCASSERT(childSize.width != 0 && childSize.height != 0, "When using OAutoSizeLayout, any child added must have its ContentSize set!");
        Widget* childAsWidget = dynamic_cast<Widget*>(child);
        const LayoutParameter* childLOP = childAsWidget->getLayoutParameter();
        if (childAsWidget != nullptr)
        {
            CCASSERT(nullptr != childLOP, "When using OAutoSizeLayout, any Widget child added must have its LayoutParameter set!");
        }
        float hTotalMargin = childLOP != nullptr ? childLOP->getMargin().left + childLOP->getMargin().right : 0;
        float vTotalMargin = childLOP != nullptr ? childLOP->getMargin().top + childLOP->getMargin().bottom : 0;
        float newWidth = -1;
        float newHeigth = -1;
        if (getLayoutType() == Type::HORIZONTAL)
        {
            // Horizontal arrangement :		1. width is the sum of children widths (+ margins)
            //								2. Height is the greatest heigth (+ margins)
            _childrenTotalSize.width += hTotalMargin + childSize.width;
            if (_childrenTotalSize.height < vTotalMargin + childSize.height)
                _childrenTotalSize.height = vTotalMargin + childSize.height;
        }
        else if (getLayoutType() == Type::VERTICAL)
        {
            // Horizontal arrangement :		1. height is the sum of children heightss (+ margins)
            //								2. width is the greatest width (+ margins)
            _childrenTotalSize.height += vTotalMargin + childSize.height;
            if (_childrenTotalSize.width < hTotalMargin + childSize.width)
                _childrenTotalSize.width = hTotalMargin + childSize.width;
        }
        updateContentSize();
    }

    void AutoSizeLayout::updateContentSize()
    {
        setContentSize(Size(_childrenTotalSize.width > _backGroundSize.width ? _childrenTotalSize.width : _backGroundSize.width,
                            _childrenTotalSize.height > _backGroundSize.height ? _childrenTotalSize.height : _backGroundSize.height));
    }

    void AutoSizeLayout::setBackGroundFrame(string frame)
    {
        setBackGroundImage(frame, Widget::TextureResType::PLIST);

        _backGroundSize = _backGroundImage->getContentSize();
        updateContentSize();
    }

}
