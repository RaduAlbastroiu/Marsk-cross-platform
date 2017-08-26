//
//  ProjectilesEnemy.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectiles/Projectile.h"
#include "Projectiles/Projectiles.h"
#include "Header.h"

using namespace std;
USING_NS_CC;

class ProjectilesEnemy : public Projectiles
{
public:

    ~ProjectilesEnemy();
    
    void addSimpleProjectile(cocos2d::Scene* scene, Sprite* enemySpaceShip, float speed) override;
};

