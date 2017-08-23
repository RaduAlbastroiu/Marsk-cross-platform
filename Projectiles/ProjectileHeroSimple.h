//
//  ProiectileHeroSimple.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "cocos2d.h"
USING_NS_CC;

class ProjectileHeroSimple : public Projectile
{
public:
    // constructor
    ProjectileHeroSimple(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed);
    // destructor
    ~ProjectileHeroSimple();
    
    // override methods
    
    // collsision with another object
    bool collisionWithObject(cocos2d::Sprite* aSprite) override;
    // update position of a proiectile and if it fails will return false
    bool isStillInViewArea() override;
    
private:
    float scale;
    float speed;
    cocos2d::Scene* scene;
    cocos2d::Sprite* projectile;
    
};
  
