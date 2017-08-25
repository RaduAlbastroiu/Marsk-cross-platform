//
//  InputControlMovementArrows.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControl.h"
#include "Entities/Hero.h"

USING_NS_CC;
using namespace std;

class InputControlMovementArrows : public InputControl
{
    
public:
    
    // constructor
    InputControlMovementArrows(cocos2d::Scene* aScene, Hero* aEntity);
    
    void update(float delta) override;
    
    bool touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(const cocos2d::Touch* touch, cocos2d::Event* event);
    bool touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event);
    
private:
    
    void setTouchListener();
    
    void addInputVisualButtons();
    
    void addLeftMovementArrow();
    void addRightMovementArrow();
    
    void loadMovementArrowLeftSelected();
    void loadMovementArrowRightSelected();
    void loadMovementArrowLeftUnselected();
    void loadMovementArrowRightUnselected();
    
    float leftArrowPositionX;
    float leftArrowPositionY;
    float rightArrowPositionX;
    float rightArrowPositionY;
    
    cocos2d::Sprite* leftArrow;
    cocos2d::Sprite* rightArrow;
    
    cocos2d::Touch* leftArrowTouch;
    cocos2d::Touch* rightArrowTouch;
    
    bool leftArrowPressed;
    bool rightArrowPressed;
    
};


