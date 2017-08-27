//
//  Entity.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "Header.h"
#include "Projectiles/Projectiles.h"

using namespace std;
USING_NS_CC;

// abstract class
// used just as an interface
class Entity
{
public:
    
    virtual ~Entity();
    
    virtual void update(float delta) = 0;
    
    virtual void fireSimpleProjectile() = 0;
    
    virtual void moveLeft(float delta) = 0;
    virtual void moveRight(float delta) = 0;
    virtual void moveStop() = 0;
    
    virtual bool isAlive() = 0;

protected:
    
    int nrLifes;
    
    virtual void setTextureCenter() = 0;
    virtual void setTextureLeft() = 0;
    virtual void setTextureRight() = 0;

};
