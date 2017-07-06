//
//  Proiectiles.cpp
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

void Proiectiles::update()
{
    //do nothing now
}

// Hero proiectile shot verify for collision
bool Proiectiles::collisionWithEnemy(cocos2d::Sprite* refSprite)
{
    // check all hero proiectiles
    for(auto& proiectile : HeroProiectiles)
    {
        // if proiectile hit
        if(proiectile->collisionWithObject(refSprite))
        {
            // delete proiectile
            auto it = find(HeroProiectiles.begin(), HeroProiectiles.end(), proiectile);
            HeroProiectiles.erase(it);
            
            // return true for collision
            return true;
        }
    }
    
    return false;
}
