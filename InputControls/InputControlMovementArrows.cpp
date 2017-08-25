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
#include "InputControls/InputControlMovementArrows.h"

// constructor
InputControlMovementArrows::InputControlMovementArrows(cocos2d::Scene* aScene, Hero* aEntity)
{
    
    targetScene = aScene;
    targetEntity = aEntity;

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

// touch began
bool InputControlMovementArrows::touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event)
{
    if(leftArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowLeftSelected();
            
        leftArrowPressed = true;
    }
        
    if(rightArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowRightSelected();

        rightArrowPressed = true;
    }
    
}

// touch moved
void InputControlMovementArrows::touchMoved(const cocos2d::Touch* touch, cocos2d::Event* event)
{
    // if the touch moved outside the left arrow box
    if(leftArrowPressed == true &&
       !leftArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowLeftUnselected();
        
        leftArrowPressed = false;
    }
    
    // if the touch moved outside the right arrow box
    if(rightArrowPressed == true &&
       !rightArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowRightUnselected();
        
        rightArrowPressed = false;
    }
    
}

// touch ended
bool InputControlMovementArrows::touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event)
{

    if(leftArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowLeftUnselected();
            
        leftArrowPressed = false;
        
        // if the touch finised left movement
        return true;
    }
        
    if(rightArrow->getBoundingBox().containsPoint(touch->getLocation()))
    {
        loadMovementArrowRightUnselected();
            
        rightArrowPressed = false;
        
        // if the touch finised right movement
        return true;
    }
    
    // if the touch didn't finished a movement action
    return false;

}

// add left movement arrow
void InputControlMovementArrows::addLeftMovementArrow()
{
    leftArrow = cocos2d::Sprite::create("res/leftArrow.png");
    leftArrow->setAnchorPoint(cocos2d::Vec2(0.5,0.5));
    leftArrow->setScale(0.5);
    leftArrow->setPosition(targetScene->getBoundingBox().getMaxX() * 0.075, targetScene->getBoundingBox().getMaxY() * 0.20 );
    
    targetScene->addChild(leftArrow, 1);
}

// add right movement arrow
void InputControlMovementArrows::addRightMovementArrow()
{
    rightArrow = cocos2d::Sprite::create("res/rightArrow.png");
    rightArrow->setAnchorPoint(cocos2d::Vec2(0.5,0.5));
    rightArrow->setScale(0.5);
    rightArrow->setPosition(targetScene->getBoundingBox().getMaxX() * 0.925, targetScene->getBoundingBox().getMaxY() * 0.20 );
    
    targetScene->addChild(rightArrow, 1);
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
        targetEntity->moveLeft(delta);
    
    
    if (rightArrowPressed && !leftArrowPressed)
        targetEntity->moveRight(delta);
    
    if (!leftArrowPressed && !rightArrowPressed)
        targetEntity->moveStop();
    
}



