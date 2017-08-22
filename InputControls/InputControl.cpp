//
//  InputControl.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControls.h"
#include "Entities/Entity.h"

// constructor
InputControl::InputControl(cocos2d::Scene* aScene, Entity* aEntity)
:currentScene(aScene), currentEntity(aEntity)
{
}

// destructor
InputControl::~InputControl()
{
    delete currentEntity;
    delete currentScene;
}
