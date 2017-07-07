//
//  ProjectileFactoryEnemy.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectile.h"
#include "ProjectileFactory.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
USING_NS_CC;
using namespace std;

class ProjectileFactoryEnemy : public ProjectileFactory
{
public:
    ProjectileFactoryEnemy(ProjectilesEnemy* aProjectiles);
    void addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale);
    
private:
    ProjectilesEnemy* ProjectileContainer;
};
