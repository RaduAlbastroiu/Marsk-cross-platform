//
//  Projectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
USING_NS_CC;

// abstract class
class Projectiles
{
public:
    virtual ~Projectiles() = default;

    void update();
    
    virtual bool collisionWith(cocos2d::Sprite* aObj);
    
    virtual void addSimpleProjectile(cocos2d::Scene* aScene, Sprite* aEntity, float aSpeed, float aScale) = 0;
    
protected:
    vector< Projectile* > projectilesContainer;
    
};
