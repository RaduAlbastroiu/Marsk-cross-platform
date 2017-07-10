//
//  InputControlMovementArrows.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControlMovement.h"
#include "Movement/Movement.h"
#include "Movement/Move.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class InputControlMovementArrows : public InputControlMovement
{
    
public:
    
    // constructor
    InputControlMovementArrows(cocos2d::Scene* aScene, Entity* aEntity);
    
    void addInputVisualButtons() override;
    void addLeftMovementArrow();
    void addRightMovementArrow();
    
private:
    
    float leftArrowPositionX;
    float leftArrowPositionY;
    float rightArrowPositionX;
    float rightArrowPositionY;
    
    cocos2d::Sprite* leftArrow;
    cocos2d::Sprite* rightArrow;
    
};
