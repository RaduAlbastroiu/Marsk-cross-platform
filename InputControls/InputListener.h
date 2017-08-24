//
//  InputListener.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/24/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControlMovementArrows.h"
#include "InputControls/InputControlProjectiles.h"
USING_NS_CC;

class InputListener : public cocos2d::Layer
{

public:

    // constructor
    InputListener(InputControlMovementArrows* aArrow, InputControlProjectiles* aProjecctile);
    
    bool touchBegan(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchMoved(const cocos2d::Touch* touch, cocos2d::Event* event);
    void touchEnded(const cocos2d::Touch* touch, cocos2d::Event* event);
    
private:
    
    InputControlMovementArrows* Arrow;
    InputControlProjectiles* Projecctile;
    
    cocos2d::EventListenerTouchOneByOne* touchListener;

};
