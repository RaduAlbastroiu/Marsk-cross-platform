//
//  Enemy.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#include "Entities/Enemy.h"

// constructor
Enemy::Enemy(cocos2d::Scene* scene, float positionX, float positionY)
:posX(positionX),posY(positionY)
{
    
    // asign projectile object
    projectileEntity = dynamic_cast<Projectiles*>(new ProjectilesEnemy());
    
    currentScene = scene;
    
    // random number for speed
    speedSpaceShip = 5;
    speedEnemyProjectiles = 1;
    nrLifes = 1;
    
    loadSpaceShip();
}

// destructor
Enemy::~Enemy()
{
    currentScene->removeChild(spaceShip);
    delete projectileEntity;
    delete spaceShip;
}

// update
void Enemy::update(float delta)
{
    // update projectiles
    projectileEntity->update();
}

void Enemy::fireSimpleProjectile()
{
    projectileEntity->addSimpleProjectile(currentScene, spaceShip, speedEnemyProjectiles);
}

void Enemy::moveLeft(float delta)
{
    if(spaceShip->getBoundingBox().getMinX() > currentScene->getBoundingBox().getMinX())
    {
        setTextureLeft();
        spaceShip->runAction(MoveBy::create(delta, Vec2(-speedSpaceShip, 0)));
    }
}

void Enemy::moveRight(float delta)
{
    if(spaceShip->getBoundingBox().getMaxX() < currentScene->getBoundingBox().getMaxX())
    {
        setTextureRight();
        spaceShip->runAction(MoveBy::create(delta, Vec2(+speedSpaceShip, 0)));
    }
}

void Enemy::moveStop()
{
    setTextureCenter();
}

void Enemy::setTextureLeft()
{
    //heroSpaceShip->setTexture("res/elonLeft.png");
}

void Enemy::setTextureRight()
{
    //heroSpaceShip->setTexture("res/elonRight.png");
}

void Enemy::setTextureCenter()
{
    //heroSpaceShip->setTexture("res/elonCenter.png");
}

void Enemy::loadSpaceShip()
{
    
    spaceShip = cocos2d::Sprite::create("res/redShip.png");
    spaceShip->setAnchorPoint(Vec2(0.5, 0.5));
    spaceShip->setPosition(posX, posY);
    
    spaceShip->setScale(0.2);
    currentScene->addChild(spaceShip);
    
}

bool Enemy::isAlive()
{
    if(nrLifes)
        return true;
    return false;
}

Projectiles* Enemy::getProjectile()
{
    return projectileEntity;
}

void Enemy::hit()
{
    nrLifes = 0;
}

