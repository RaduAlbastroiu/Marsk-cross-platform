//
//  Projectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"

// check collisions
bool Projectiles::collisionWith(cocos2d::Sprite* aObj)
{
    auto size = projectilesContainer.size();
    
    // check all projectiles
    projectilesContainer.erase(
                               remove_if(projectilesContainer.begin(), projectilesContainer.end(),
                                         [&](const auto & aProjectile) { return aProjectile->collisionWithObject(aObj); }),
                               projectilesContainer.end());
    
    if(size != projectilesContainer.size())
        return true;
    
    return false;

}

void Projectiles::update()
{
    projectilesContainer.erase(
                               remove_if(projectilesContainer.begin(), projectilesContainer.end(),
                                         [](const auto & aProjectile) { return aProjectile->isStillInViewArea() == false; }),
                               projectilesContainer.end());
}
