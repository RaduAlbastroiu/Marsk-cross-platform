//
//  ProjectilesEnemy.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include <stdio.h>
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectileFactoryEnemy.h"
#include "Projectiles/ProjectilesEnemy.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
USING_NS_CC;
using namespace std;

// constructor
ProjectilesEnemy::ProjectilesEnemy()
{
    ProjectileFactory* newFactory = new ProjectileFactoryEnemy(this);
    factory = newFactory;
}

// destructor
ProjectilesEnemy::~ProjectilesEnemy()
{
    delete factory;
    projectilesContainer.clear();
}

// add new enemy projectile
void ProjectilesEnemy::addProjectile(Projectile* aProjectile)
{
    unique_ptr<Projectile> ptr = make_unique<Projectile>(*aProjectile);
    
    projectilesContainer.push_back(ptr);
}
