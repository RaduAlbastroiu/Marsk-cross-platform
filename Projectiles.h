//
//  Projectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Projectile.h"
#include "HeroProjectile.h"
#include "ProjectileFactory.h"
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
    void addProjectile(unique_ptr<Projectile> aProjectile) = 0;
    bool collisionWithEnemy(cocos2d::Sprite* aObj) = 0;

};
