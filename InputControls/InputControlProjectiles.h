//
//  InputControlProjectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Entities/Entity.h"


class InputControlProjectiles : public InputControl
{
    
public:
    
    // constructor
    InputControlProjectiles(cocos2d::Scene* aScene, Entity* aEntity);
    
    // destructor
    ~InputControlProjectiles() = default;
    
    cocos2d::EventListener* getListener() override;
    
    virtual void update(float delta) override;
    
private:
    
    void setTouchListener();
    
    void touchBegan(const vector<cocos2d::Touch*> touch, cocos2d::Event* event);
    void touchEnded(const vector<cocos2d::Touch*> touch, cocos2d::Event* event);
    
    
    cocos2d::EventListenerTouchAllAtOnce* touchListener;
    
    int nrTouches;
    bool fireProjectile;
    
};
