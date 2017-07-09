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
    virtual void addProjectile(unique_ptr<Projectile> aProjectile) = 0;
    virtual bool collisionWith(cocos2d::Sprite* aObj);
    virtual void update();

    virtual ~Projectiles() = default;
    
protected:
    vector< unique_ptr <Projectile> > projectilesContainer;

};
