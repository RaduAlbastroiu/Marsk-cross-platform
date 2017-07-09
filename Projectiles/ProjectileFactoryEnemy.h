//
//  ProjectileFactoryEnemy.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "Projectiles/ProjectileFactory.h"
#include "Projectiles/ProjectilesEnemy.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
USING_NS_CC;
using namespace std;

class ProjectileFactoryEnemy : public ProjectileFactory
{
public:
    ProjectileFactoryEnemy(ProjectilesEnemy* aProjectilesHero);
    void addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale);
    
private:
    ProjectilesEnemy* ProjectileContainer;
};
