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
#include "InputControls/InputControls.h"
#include "Projectiles/Projectiles.h"

using namespace std;
USING_NS_CC;

class Entity
{
public:
    
    void update(float delta);
    
    virtual void fireSimpleProjectile() = 0;
    
    virtual void moveLeft(float delta) = 0;
    virtual void moveRight(float delta) = 0;
    virtual void moveStop() = 0;

protected:
    
    virtual void setTextureCenter() = 0;
    virtual void setTextureLeft() = 0;
    virtual void setTextureRight() = 0;

    Projectiles* projectileEntity;

};
