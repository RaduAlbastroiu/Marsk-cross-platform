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
#include "cocos2d.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>

using namespace std;
USING_NS_CC;

class ProjectilesEnemy : public Projectiles
{
public:

    virtual ~ProjectilesEnemy() = default;
    
    void addSimpleProjectile(cocos2d::Scene* scene, Sprite* enemySpaceShip, float speed) override;
};

