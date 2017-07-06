//
//  Projectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include <stdio.h>
#include "Projectiles.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

// Hero projectile verify for collision
bool Projectiles::collisionWithEnemy(cocos2d::Sprite* aSprite)
{
    // check all hero projectiles
    for(auto& someProjectile : HeroProjectiles)
    {
        // if projectile hit
        if(someProjectile->collisionWithObject(aSprite))
        {
            // delete projectile
            auto it = find(HeroProjectiles.begin(), HeroProjectiles.end(), someProjectile);
            HeroProjectiles.erase(it);
            
            // return true for collision
            return true;
        }
    }
    
    return false;
}
