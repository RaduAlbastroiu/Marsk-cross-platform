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
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class InputControlMovementArrows : public InputControlMovement
{
    
public:
    
    // constructor
    InputControlMovementArrows(cocos2d::Scene* aScene, Entity* aEntity);
    
    // destructor
    ~InputControlMovementArrows() = default;
    
    void addInputVisualButtons() override;
    
    cocos2d::EventListener* getListener() override;
    
    virtual void update(float delta) override;
    
    bool touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(const cocos2d::Touch* touch, cocos2d::Event* event);
    bool touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event);
    
private:
    
    // some redesign for arrows may be needed
    
    void setTouchListener();
    

    
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


