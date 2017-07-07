//
//  ProjectileFactory.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectile.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
USING_NS_CC;
using namespace std;

class ProjectileFactory
{
public:
    virtual void addProjectileSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale) = 0;
    
    virtual ~ProjectileFactory() = default;
};
