//
//  Hero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "Entities/Hero.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControlMovement.h"
#include "Projectiles/ProjectilesHero.h"

Hero::Hero(cocos2d::Scene* scene, float speed)
{

    // asign projectile object
    projectileEntity = dynamic_cast<Projectiles*>(new ProjectilesHero());
    
    currentScene = scene;
    
    // random number for speed
    speedHeroSpaceShip = 5;
    speedHeroProjectiles = 5;
    
    loadHeroSpaceship();
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

void Hero::loadHeroSpaceship()
{
    heroSpaceShip = cocos2d::Sprite::create("res/elonBack.png");
    heroSpaceShip->setAnchorPoint(Vec2(0.5, 0.5));
    heroSpaceShip->setPosition(currentScene->getBoundingBox().getMidX(), currentScene->getBoundingBox().size.height / 7);
    heroSpaceShip->setScale(0.3);
    currentScene->addChild(heroSpaceShip);
}

