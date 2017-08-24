//
//  InputListener.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/24/17.
//
//

#pragma once
#include <stdio.h>
#include "InputControls/InputListener.h"

using namespace std;

InputListener::InputListener(InputControlMovementArrows* aArrow, InputControlProjectiles* aProjecctile)
:Arrow(Arrow), Projecctile(aProjecctile)
{
    // create touch listener
    touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(InputListener::touchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(InputListener::touchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(InputListener::touchEnded, this);

    touchListener->setSwallowTouches(true);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

// touch happened
bool InputListener::touchBegan(const cocos2d::Touch* touch, cocos2d::Event *event)
{
    if( /* call arrow */)
        return true;
    
    // call projectile
    return true;
}
