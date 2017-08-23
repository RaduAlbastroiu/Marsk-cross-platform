//
//  InputControlProjectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControlProjectiles.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Entities/Entity.h"
using namespace std;

// constructor
InputControlProjectiles::InputControlProjectiles(cocos2d::Scene* aScene, Entity* aEntity)
:InputControl(aScene, aEntity)
{
    nrTouches = 0;
    fireProjectile = false;
}

cocos2d::EventListener* InputControlProjectiles::getListener()
{
    return dynamic_cast<cocos2d::EventListener*>(touchListener);
}

// add touch listener
void InputControlProjectiles::setTouchListener()
{
    touchListener = EventListenerTouchAllAtOnce::create();
    
    touchListener->onTouchesBegan = CC_CALLBACK_2(InputControlProjectiles::touchBegan, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(InputControlProjectiles::touchEnded, this);
    
}

// touch began
void InputControlProjectiles::touchBegan(const vector<cocos2d::Touch*> touch, cocos2d::Event* event)
{
    nrTouches += touch.size();
    fireProjectile = false;
}

// touch ended
void InputControlProjectiles::touchEnded(const vector<cocos2d::Touch*> touch, cocos2d::Event* event)
{
    // if there were touches and now there are no more
    if(nrTouches - touch.size() == 0 && touch.size())
        fireProjectile = true;
    
    nrTouches -= touch.size();
}

void InputControlProjectiles::update(float delta)
{
    if(fireProjectile)
    {
        currentEntity->fireSimpleProjectile();
    }
}

