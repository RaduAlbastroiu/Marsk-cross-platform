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
#include "Projectiles/ProjectilesEnemy.h"
#include "Projectiles/ProjectileEnemySimple.h"

USING_NS_CC;
using namespace std;

// destructor
ProjectilesEnemy::~ProjectilesEnemy()
{
    for(auto it = projectilesContainer.begin(); it != projectilesContainer.end(); ++it)
    {
        delete (*it);
    }
    projectilesContainer.clear();
}

// add new enemy projectile simple
void ProjectilesEnemy::addSimpleProjectile(cocos2d::Scene* scene, Sprite* enemySpaceShip, float speed)
{
    Projectile* ptr = new ProjectileEnemySimple(scene, enemySpaceShip, speed);
    
    projectilesContainer.push_back(ptr);
}
