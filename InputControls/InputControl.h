//
//  InputControl.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Hero.h"

USING_NS_CC;
using namespace std;

// abstract class
class InputControl
{
public:
    
    // pure virtual method
    virtual void addInputVisualButtons();
    
    virtual cocos2d::EventListener* getListener();
    
    virtual void update(float delta) = 0;
    
protected:
    
    Hero* targetEntity;
    cocos2d::Scene* targetScene;
    
};
