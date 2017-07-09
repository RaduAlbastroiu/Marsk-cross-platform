//
//  Projectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "Projectiles/ProjectileFactory.h"
#include "Projectiles/ProjectileFactoryHero.h"
#include "Projectiles/ProjectileFactoryEnemey.h"
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
    virtual void add(Projectile* aProjectile) = 0;
    virtual bool collisionWith(cocos2d::Sprite* aObj);
    virtual void update();
    
    void addSimpleProjectile(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale);

    virtual ~Projectiles() = default;
    
protected:
    vector< unique_ptr <Projectile> > projectilesContainer;
    ProjectileFactory* factory;
};
