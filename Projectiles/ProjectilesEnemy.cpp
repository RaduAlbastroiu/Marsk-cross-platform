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
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
USING_NS_CC;
using namespace std;

// add new enemy projectile simple
void ProjectilesEnemy::addSimpleProjectile(cocos2d::Scene* scene, Sprite* enemySpaceShip, float speed, float scale)
{
    Projectile* ptr = new ProjectileEnemySimple(scene, enemySpaceShip, speed, scale);
    
    projectilesContainer.push_back(ptr);
}
