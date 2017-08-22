//
//  InputControlMovement.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControlMovement.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Movement/Movement.h"
#include "Movement/Move.h"
#include "Entities/Entity.h"

InputControlMovement::InputControlMovement(cocos2d::Scene* aScene, Entity* aEntity)
{
    currentScene = aScene;
    currentEntity = aEntity;
}
