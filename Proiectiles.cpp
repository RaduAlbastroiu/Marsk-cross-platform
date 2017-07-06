//
//  Proiectiles.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include <stdio.h>
#include "Proiectiles.h"
#include "cocos2d.h"
USING_NS_CC;

void Proiectiles::update()
{
    //do nothing now
}

bool Proiectiles::collisionWithEnemy(cocos2d::Sprite* refSprite)
{
    for(auto proiectile : HeroProiectiles)
    {
        if(proiectile->hits(refSprite))
        {
            // delete proiectile
            return true;
        }
    }
}
