//
//  Entity.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Entities.h"
#include "Movement/Movement.h"
#include "InputControls/InputControls.h"

using namespace std;
USING_NS_CC;

class Entity
{
public:
    
    virtual void addEntity() = 0;

protected:

    InputControls* inputControl;
    Movement* moveWorker;

};
