//
//  ProjectilesEnemy.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include <stdio.h>
#include "Projectile.h"
#include "Projectiles.h"
#include "ProjectilesEnemy.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
USING_NS_CC;
using namespace std;

// add new enemy projectile
void ProjectilesEnemy::addProjectile(Projectile* aProjectile)
{
    unique_ptr<Projectile> ptr = make_unique<Projectile>(*aProjectile);
    
    this->Projectiles.push_back(ptr);
}

// Enemy projectile verify for collision
bool ProjectilesEnemy::collisionWithHero(cocos2d::Sprite* aSprite)
{
    // check all enemy projectiles
    for(auto& someProjectile : Projectiles)
    {
        // if projectile hit
        if(someProjectile->collisionWithObject(aSprite))
        {
            // delete projectile
            auto it = find(Projectiles.begin(), Projectiles.end(), someProjectile);
            Projectiles.erase(it);
            
            // return true for collision
            return true;
        }
    }
    
    return false;
}
