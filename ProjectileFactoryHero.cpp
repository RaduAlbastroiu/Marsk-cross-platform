//
//  ProjectileFactoryHero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#include <stdio.h>
#include "ProjectilesHero.h"
#include "ProjectileHeroSimple.h"
#include "ProjectileFactoryHero.h"

ProjectileFactoryHero::ProjectileFactoryHero(ProjectilesHero* aProjectileHero):
ProjectileContainer(aProjectileHero)
{}

void ProjectileFactoryHero::addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    Projectile* ptr = new ProjectileHeroSimple(aScene, aHeroSpaceShip, aSpeed, aScale);
    
    ProjectileContainer->addProjectile(ptr);
}
