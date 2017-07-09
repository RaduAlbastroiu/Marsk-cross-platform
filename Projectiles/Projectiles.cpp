//
//  Projectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include <stdio.h>
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

// check collisions
bool Projectiles::collisionWith(cocos2d::Sprite* aObj)
{
    // check all projectiles
    for(auto& someProjectile : projectilesContainer)
    {
        // if projectile hit
        if(someProjectile->collisionWithObject(aObj))
        {
            // delete projectile
            auto it = find(projectilesContainer.begin(), projectilesContainer.end(), someProjectile);
            projectilesContainer.erase(it);
            
            // return true for collision
            return true;
        }
    }
    
    return false;
}

void Projectiles::update()
{
    for(auto &someProjectile : projectilesContainer)
    {
        if(someProjectile->isStillInViewArea())
            continue;
        else
        {
            // delete projectile
            auto it = find(projectilesContainer.begin(), projectilesContainer.end(), someProjectile);
            projectilesContainer.erase(it);
        }
    }
}

// call factory for a new object
void Projectiles::addSimpleProjectile(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    factory->addProjectileSimple(aScene, aHeroSpaceShip, aSpeed, aScale);
}
