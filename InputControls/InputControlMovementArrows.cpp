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
#include "Entities/Entity.h"

// constructor
InputControlMovementArrows::InputControlMovementArrows(cocos2d::Scene* aScene, Entity* aEntity)
{
    currentScene = aScene;
    currentEntity = aEntity;
    
    leftArrowPressed = false;
    rightArrowPressed = false;
    leftArrowPositionX = 0.075;
    leftArrowPositionY = 0.2;
    rightArrowPositionX = 0.925;
    rightArrowPositionY = 0.2;

    addInputVisualButtons();
    setTouchListener();
}

// add movement arrows
void InputControlMovementArrows::addInputVisualButtons()
{
    addLeftMovementArrow();
    addRightMovementArrow();
    
    setTouchListener();
}

cocos2d::EventListener* InputControlMovementArrows::getListener()
{
    return dynamic_cast<cocos2d::EventListener*>(touchListener);
}

// add touch listener
void InputControlMovementArrows::setTouchListener()
{
    touchListener = EventListenerTouchAllAtOnce::create();
    
    touchListener->onTouchesBegan = CC_CALLBACK_2(InputControlMovementArrows::touchBegan, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(InputControlMovementArrows::touchEnded, this);
    
}

// touch began
void InputControlMovementArrows::touchBegan(const vector<cocos2d::Touch*> touch, cocos2d::Event* event)
{
    for(auto oneTouch : touch)
    {
        if(leftArrow->getBoundingBox().containsPoint(oneTouch->getLocation()))
        {
            loadMovementArrowLeftSelected();
            
            leftArrowPressed = true;
        }
        
        if(rightArrow->getBoundingBox().containsPoint(oneTouch->getLocation()))
        {
            loadMovementArrowRightSelected();

            rightArrowPressed = true;
        }
    }
}

// touch ended
void InputControlMovementArrows::touchEnded(const vector<cocos2d::Touch*> touch, cocos2d::Event* event)
{
    for(auto oneTouch : touch)
    {
        if(leftArrow->getBoundingBox().containsPoint(oneTouch->getLocation()))
        {
            loadMovementArrowLeftUnselected();
            
            leftArrowPressed = false;
        }
        
        if(rightArrow->getBoundingBox().containsPoint(oneTouch->getLocation()))
        {
            loadMovementArrowRightUnselected();
            
            rightArrowPressed = false;
        }
    }
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

void InputControlMovementArrows::loadMovementArrowLeftSelected()
{
    leftArrow->setTexture("res/leftArrowPressed.png");
}

void InputControlMovementArrows::loadMovementArrowRightSelected()
{
    leftArrow->setTexture("res/rightArrowPressed.png");
}

void InputControlMovementArrows::loadMovementArrowLeftUnselected()
{
    leftArrow->setTexture("res/leftArrow.png");
}

void InputControlMovementArrows::loadMovementArrowRightUnselected()
{
    leftArrow->setTexture("res/rightArrowPressed.png");
}

// update
void InputControlMovementArrows::update(float delta)
{
    
    if (leftArrowPressed && !rightArrowPressed)
        currentEntity->moveLeft(delta);
    
    
    if (rightArrowPressed && !leftArrowPressed)
        currentEntity->moveRight(delta);
    
    if (!leftArrowPressed && !rightArrowPressed)
        currentEntity->moveStop();
    
}



