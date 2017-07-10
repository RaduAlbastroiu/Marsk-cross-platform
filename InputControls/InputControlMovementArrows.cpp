//
//  InputControlMovementArrows.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControlMovement.h"
#include "InputControls/InputControlMovementArrows.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Movement/Movement.h"
#include "Movement/Move.h"
#include "Entities/Entity.h"

// constructor
InputControlMovementArrows::InputControlMovementArrows(cocos2d::Scene* aScene, Entity* aEntity) : InputControlMovement(aScene, aEntity)
{
    leftArrowPositionX = 0.075;
    leftArrowPositionY = 0.2;
    rightArrowPositionX = 0.925;
    rightArrowPositionY = 0.2;

    addInputVisualButtons();
}

// add movement arrows
void InputControlMovementArrows::addInputVisualButtons()
{
    addLeftMovementArrow();
    addRightMovementArrow();
}

// add left movement arrow
void InputControlMovementArrows::addLeftMovementArrow()
{
    leftArrow = cocos2d::Sprite::create("res/leftArrow.png");
    leftArrow->setAnchorPoint(cocos2d::Vec2(0.5,0.5));
    leftArrow->setScale(0.5);
    leftArrow->setPosition(currentScene->getBoundingBox().getMaxX() * 0.075, currentScene->getBoundingBox().getMaxY() * 0.20 );
    
    currentScene->addChild(leftArrow, 1);
}

// add right movement arrow
void InputControlMovementArrows::addRightMovementArrow()
{
    rightArrow = cocos2d::Sprite::create("res/rightArrow.png");
    rightArrow->setAnchorPoint(cocos2d::Vec2(0.5,0.5));
    rightArrow->setScale(0.5);
    rightArrow->setPosition(currentScene->getBoundingBox().getMaxX() * 0.925, currentScene->getBoundingBox().getMaxY() * 0.20 );
    
    currentScene->addChild(rightArrow, 1);
}
