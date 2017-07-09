//
//  ProjectileFactoryEnemy.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#include <stdio.h>
#include "ProjectilesEnemy.h"
#include "ProjectileEnemySimple.h"
#include "ProjectileFactoryEnemy.h"

ProjectileFactoryEnemy::ProjectileFactoryEnemy(ProjectilesEnemy* aProjectile):
ProjectileContainer(aProjectile)
{}

void ProjectileFactoryEnemy::addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    Projectile* ptr = new ProjectileEnemySimple(aScene, aHeroSpaceShip, aSpeed, aScale);
    
    ProjectileContainer->addProjectile(ptr);
}
