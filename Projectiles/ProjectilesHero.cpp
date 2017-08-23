//
//  ProjectilesHero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include <stdio.h>
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectilesHero.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
USING_NS_CC;
using namespace std;

// add new hero projectile simple
void ProjectilesHero::addSimpleProjectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed, float scale)
{
    Projectile* ptr = new ProjectileHeroSimple(scene, heroSpaceShip, speed, scale);
    
    projectilesContainer.push_back(ptr);
}
