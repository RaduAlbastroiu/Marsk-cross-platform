//
//  Hero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "Entities/Hero.h"

// constructor
Hero::Hero(cocos2d::Scene* scene)
{

    // asign projectile object
    projectileEntity = dynamic_cast<Projectiles*>(new ProjectilesHero());
    
    currentScene = scene;
    
    // random number for speed
    speedHeroSpaceShip = 5;
    speedHeroProjectiles = 5;
    nrLifes = 3;
    
    loadHeroSpaceShip();
}

// destructor
Hero::~Hero()
{
    delete projectileEntity;
    delete heroSpaceShip;
}

// update
void Hero::update(float delta)
{
    // update projectiles
    projectileEntity->update();
}

void Hero::fireSimpleProjectile()
{
    projectileEntity->addSimpleProjectile(currentScene, heroSpaceShip, speedHeroProjectiles);
}

void Hero::moveLeft(float delta)
{
    setTextureLeft();
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(-speedHeroSpaceShip, 0)));
}

void Hero::moveRight(float delta)
{
    setTextureRight();
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(+speedHeroSpaceShip, 0)));
}

void Hero::moveStop()
{
    setTextureCenter();
}

void Hero::setTextureLeft()
{
    heroSpaceShip->setTexture("res/elonLeft.png");
}

void Hero::setTextureRight()
{
    heroSpaceShip->setTexture("res/elonRIght.png");
}

void Hero::setTextureCenter()
{
    heroSpaceShip->setTexture("res/elonCenter.png");
}

void Hero::loadHeroSpaceShip()
{
    
    heroSpaceShip = cocos2d::Sprite::create("res/elonCenter.png");
    heroSpaceShip->setAnchorPoint(Vec2(0.5, 0.5));
    heroSpaceShip->setPosition(currentScene->getBoundingBox().getMidX(),
                               currentScene->getBoundingBox().size.height / 6);
    heroSpaceShip->setScale(0.3);
    currentScene->addChild(heroSpaceShip);

}

bool Hero::isAlive()
{
    if(nrLifes)
        return true;
    return false;
}



