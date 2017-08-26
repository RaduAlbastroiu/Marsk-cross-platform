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
#include "Header.h"

class ProjectilesHero : public Projectiles
{
public:

    // destructor
    ~ProjectilesHero();

    void addSimpleProjectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed) override;
    
};

