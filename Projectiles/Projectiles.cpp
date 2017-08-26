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
    // check all projectiles
    for(auto& someProjectile : projectilesContainer)
    {
        // if projectile hit
        if(someProjectile->collisionWithObject(aObj))
        {
            // delete projectile
            auto it = find(projectilesContainer.begin(), projectilesContainer.end(), someProjectile);
            // dealocate memory
            delete (*it);
            // erase from projectiles container
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
            // dealocate memory
            delete (*it);
            // erase from projectiles container
            projectilesContainer.erase(it);

        }
    }
}
