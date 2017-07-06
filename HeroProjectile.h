//
//  HeroProiectile.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "Projectile.h"
#include "cocos2d.h"
USING_NS_CC;

class HeroProjectile : public Projectile
{
public:
    // constructor
    HeroProjectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed, float scale);
    // destructor
    ~HeroProjectile();
    
    // override methods
    
    // collsision with another object
    bool collisionWithObject(cocos2d::Sprite* aSprite) override;
    // update position of a proiectile and if it fails will return false
    bool isStillInViewArea() override;
    
private:
    float speed;
    cocos2d::Scene* scene;
    cocos2d::Sprite* projectile;
    
};
