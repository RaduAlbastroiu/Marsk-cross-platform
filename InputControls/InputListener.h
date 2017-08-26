//
//  InputListener.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/24/17.
//
//

#pragma once
#include "Header.h"
#include "InputControls/InputControlMovementArrows.h"
#include "InputControls/InputControlProjectiles.h"
USING_NS_CC;

// this Layer class has to be add as a child of the scene
class InputListener : public cocos2d::Layer
{

public:

    // constructor
    InputListener(InputControlMovementArrows* aArrow, InputControlProjectiles* aProjecctile);
    
    // destructor
    ~InputListener();
    
    bool touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event);
    
private:
    
    InputControlMovementArrows* Arrow;
    InputControlProjectiles* Projectile;
    
    cocos2d::EventListenerTouchOneByOne* touchListener;

};
