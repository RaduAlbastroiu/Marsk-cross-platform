//
//  Enemy.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Header.h"
#include "Projectiles/Projectiles.h"
#include "Projectiles/ProjectilesEnemy.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

// implementation of entity interface
class Enemy : public Entity
{
public:
    
    // constructor
    Enemy(cocos2d::Scene* scene);
    
    // destructor
    ~Enemy();
    
    void update(float delta) override;
    
    void fireSimpleProjectile() override;
    
    void moveLeft(float delta) override;
    void moveRight(float delta) override;
    void moveStop() override;
    
    bool isAlive() override;
    
    void hit() override;
    
    Projectiles* getProjectile();
    
private:
    
    void loadSpaceShip();
    
    void setTextureCenter() override;
    void setTextureLeft() override;
    void setTextureRight() override;
    
    float speedSpaceShip;
    float speedEnemyProjectiles;
    
    Projectiles* projectileEntity;
    cocos2d::Sprite* spaceShip;
    cocos2d::Scene* currentScene;
    
};

