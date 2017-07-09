//
//  ProjectileFactoryHero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#include <stdio.h>
#include "Projectiles/ProjectilesHero.h"
#include "Projectiles/ProjectileHeroSimple.h"
#include "Projectiles/ProjectileFactoryHero.h"

ProjectileFactoryHero::ProjectileFactoryHero(ProjectilesHero* aProjectileHero):
ProjectileContainer(aProjectileHero)
{}

void ProjectileFactoryHero::addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    Projectile* ptr = new ProjectileHeroSimple(aScene, aHeroSpaceShip, aSpeed, aScale);
    
    ProjectileContainer->add(ptr);
}
