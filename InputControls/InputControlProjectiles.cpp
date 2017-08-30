//
//  InputControlProjectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "InputControls/InputControlProjectiles.h"
using namespace std;

// constructor
InputControlProjectiles::InputControlProjectiles(cocos2d::Scene* aScene, Hero* aEntity)
{
    targetScene = aScene;
    targetEntity = aEntity;
    
    fireProjectile = false;
}

// destructor
InputControlProjectiles::~InputControlProjectiles()
{
    delete targetEntity;
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
        fireProjectile = false;
        targetEntity->fireSimpleProjectile();
    }
}

