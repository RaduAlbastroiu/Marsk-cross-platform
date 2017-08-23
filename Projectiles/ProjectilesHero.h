//
//  ProjectilesHero.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectileHeroSimple.h"
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>

using namespace std;
USING_NS_CC;

class ProjectilesHero : public Projectiles
{
public:

    virtual ~ProjectilesHero() = default;

    void addSimpleProjectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed, float scale) override;
    
};

