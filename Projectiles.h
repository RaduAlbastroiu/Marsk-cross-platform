//
//  Projectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Projectile.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
USING_NS_CC;
using namespace std;

class Projectiles
{
public:
    void addHeroProjectile(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale);
    bool collisionWithEnemy(cocos2d::Sprite* aObj);
private:
    vector<Projectile*> HeroProjectiles;
    vector<Projectile*> EnemyProjectiles;
};
