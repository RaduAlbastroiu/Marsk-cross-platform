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
    
    virtual EntityRelatedObject* getRelatedObjectMovement();
    virtual EntityRelatedObject* getRelatedObjectProjectiles();
    virtual void setTextureCenter() = 0;
    virtual void setTextureLeft() = 0;
    virtual void setTextureRight() = 0;

protected:

    InputControls* inputControl;
    EntityRelatedObject* moveWorker;
    //projectiles needed another entity i guess

};
