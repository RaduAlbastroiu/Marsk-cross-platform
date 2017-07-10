//
//  InputControlMovement.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Movement/Movement.h"
#include "Movement/Move.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class InputControlMovement : public InputControl
{
    
public:
    
    InputControlMovement(cocos2d::Scene* aScene, Entity* aEntity);
    
    
private:
    
    Entity* currentEntity;
    Movement* movementObject;
    cocos2d::Scene* currentScene;
    
};
