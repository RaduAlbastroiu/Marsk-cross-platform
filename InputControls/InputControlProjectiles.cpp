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
    fireProjectile = false;
}

// touch began
void InputControlProjectiles::touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event)
{
    fireProjectile = true;
}

// touch ended
void InputControlProjectiles::touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event)
{
    fireProjectile = false;
}

void InputControlProjectiles::update(float delta)
{
    if(fireProjectile)
    {
        currentEntity->fireSimpleProjectile();
    }
}

