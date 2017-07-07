//
//  ProjectilesEnemy.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectile.h"
#include "Projectiles.h"
#include "ProjectileFactory.h"
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
    void addProjectile(Projectile* aProjectile);
    
};

