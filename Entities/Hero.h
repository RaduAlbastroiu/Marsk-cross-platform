//
//  Hero.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "Header.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectilesHero.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

// implementation of entity interface
class Hero : public Entity
{
public:
    
    // constructor
    Hero(cocos2d::Scene* scene);
    
    // destructor
    ~Hero();
    
    void update(float delta) override;
    
    void fireSimpleProjectile() override;
    
    void moveLeft(float delta) override;
    void moveRight(float delta) override;
    void moveStop() override;
    
    bool isAlive() override;
    
    void hit() override;
    
    Projectiles* getProjectile();

private:
        
    void loadHeroSpaceShip();
    void loadHeroLifes();
    
    void setTextureCenter() override;
    void setTextureLeft() override;
    void setTextureRight() override;
    
    float speedHeroSpaceShip;
    float speedHeroProjectiles;
    
    Projectiles* projectileEntity;
    cocos2d::Sprite* heroSpaceShip;
    cocos2d::Scene* currentScene;
    vector < cocos2d::Sprite* > heroLifes;
};

