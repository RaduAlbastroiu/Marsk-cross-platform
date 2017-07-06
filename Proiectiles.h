//
//  Proiectiles.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "Proiectile.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
USING_NS_CC;

class Proiectiles
{
public:
    void update();
    bool collisionWithEnemy(cocos2d::Sprite* obj);
private:
    Vector<Proiectile*> HeroProiectiles;
    Vector<Proiectile*> EnemyProiectiles;
};
