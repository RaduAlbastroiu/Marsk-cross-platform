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

USING_NS_CC;
using namespace std;

// destructor
ProjectilesHero::~ProjectilesHero()
{
    projectilesContainer.clear();
}

// add new hero projectile simple
void ProjectilesHero::addSimpleProjectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed)
{
    unique_ptr<Projectile> proj = move(make_unique<ProjectileHeroSimple>(scene, heroSpaceShip, speed));
    
    projectilesContainer.push_back(move(proj));
}
