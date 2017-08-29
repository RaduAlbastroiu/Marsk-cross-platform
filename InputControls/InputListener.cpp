//
//  InputListener.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/24/17.
//
//

#pragma once
#include "InputControls/InputListener.h"

using namespace std;

// constructor
InputListener::InputListener(InputControlMovementArrows* aArrow, InputControlProjectiles* aProjecctile)
:Arrow(aArrow), Projectile(aProjecctile)
{
    // create touch listener
    touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(InputListener::touchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(InputListener::touchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(InputListener::touchEnded, this);

    touchListener->setSwallowTouches(true);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

// destructor
InputListener::~InputListener()
{
    delete Arrow;
    delete Projectile;
    delete touchListener;
}

// touch happened
bool InputListener::touchBegan(const cocos2d::Touch* touch, cocos2d::Event *event)
{
    if(Arrow->touchBegan(touch, event))
        return true;
    
    Projectile->touchBegan(touch, event);
    
    return true;
}

// touch moved
void InputListener::touchMoved(const cocos2d::Touch* touch, cocos2d::Event *event)
{
    Arrow->touchMoved(touch, event);
}

// touch ended
void InputListener::touchEnded(const cocos2d::Touch* touch, cocos2d::Event *event)
{
    if(Arrow->touchEnded(touch, event))
        return;
    
    Projectile->touchEnded(touch, event);
}
