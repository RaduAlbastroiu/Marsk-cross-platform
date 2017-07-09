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
#include "Projectiles/ProjectileFactoryHero.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
USING_NS_CC;
using namespace std;

// constructor
ProjectilesHero::ProjectilesHero()
{
    ProjectileFactory* newFactory = new ProjectileFactoryHero(this);
    
    factory = newFactory;
}

// destructor
ProjectilesHero::~ProjectilesHero()
{
    delete factory;
    projectilesContainer.clear();
}

// add new hero projectile
void ProjectilesHero::add(Projectile* aProjectile)
{
    unique_ptr<Projectile> ptr = make_unique<Projectile>(*aProjectile);
    
    projectilesContainer.push_back(ptr);
}
