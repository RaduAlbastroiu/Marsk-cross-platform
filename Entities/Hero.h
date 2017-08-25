//
//  Hero.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectilesHero.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class Hero : public Entity
{
public:
    Hero(cocos2d::Scene* scene, float speed);
    ~Hero() = default;
    
    void fireSimpleProjectile() override;
    
    void moveLeft(float delta) override;
    void moveRight(float delta) override;
    void moveStop() override;

private:
    
    void loadHeroSpaceShip();
    
    void setTextureCenter() override;
    void setTextureLeft() override;
    void setTextureRight() override;
    
    float speedHeroSpaceShip;
    float speedHeroProjectiles;
    
    cocos2d::Sprite* heroSpaceShip;
    cocos2d::Scene* currentScene;
    
};

