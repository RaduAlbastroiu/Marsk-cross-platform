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
    speedHeroProjectiles = 1;
    nrLifes = 3;
    
    loadHeroSpaceShip();
    loadHeroLifes();
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
    if(heroSpaceShip->getBoundingBox().getMinX() > currentScene->getBoundingBox().getMinX())
    {
        setTextureLeft();
        heroSpaceShip->runAction(MoveBy::create(delta, Vec2(-speedHeroSpaceShip, 0)));
    }
}

void Hero::moveRight(float delta)
{
    if(heroSpaceShip->getBoundingBox().getMaxX() < currentScene->getBoundingBox().getMaxX())
    {
        setTextureRight();
        heroSpaceShip->runAction(MoveBy::create(delta, Vec2(+speedHeroSpaceShip, 0)));
    }
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
    heroSpaceShip->setTexture("res/elonRight.png");
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

void Hero::loadHeroLifes()
{
    for (int i = 1; i <= nrLifes; i++)
    {
        auto life = Sprite::create("res/life.png");
        life->setAnchorPoint(Vec2(0.5, 0.5));
        life->setScale(0.125);
        int x = currentScene->getBoundingBox().size.width - (i * life->getBoundingBox().size.width);
        int y = currentScene->getBoundingBox().size.height * 0.895;
        life->setPosition(Vec2(x, y));
        heroLifes.push_back(life);
        currentScene->addChild(life, 3);
    }
}

bool Hero::isAlive()
{
    if(nrLifes)
        return true;
    return false;
}

Projectiles* Hero::getProjectile()
{
    return projectileEntity;
}

void Hero::hit()
{
    // destroy one life and animation for hero spaceship
    if (nrLifes)
    {
        currentScene->removeChild(heroLifes[heroLifes.size() - 1]);
        heroLifes.pop_back();
        nrLifes--;
    }
    if (nrLifes == 0)
    {
        // run explosion
        currentScene->removeChild(heroSpaceShip);
    }
}

