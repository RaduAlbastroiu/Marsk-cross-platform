//
//  Projectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Header.h"
#include "Projectiles/Projectile.h"

// abstract class
class Projectiles
{
public:

    virtual ~Projectiles() = default;

    void update();
    
    virtual bool collisionWith(cocos2d::Sprite* aObj);
    
    virtual void addSimpleProjectile(cocos2d::Scene* aScene, Sprite* aEntity, float aSpeed) = 0;
    
protected:
    vector< Projectile* > projectilesContainer;
    
};
