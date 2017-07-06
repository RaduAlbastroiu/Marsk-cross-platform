//
//  Hero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "Hero.h"

Hero::Hero(cocos2d::Scene* scene, float speed)
{
    currentScene = scene;
    heroSpeed = speed;
    loadHeroSpaceship();
}

void Hero::loadHeroSpaceship()
{
    heroSpaceShip = cocos2d::Sprite::create("res/elonBack.png");
    heroSpaceShip->setAnchorPoint(Vec2(0.5, 0.5));
    heroSpaceShip->setPosition(currentScene->getBoundingBox().getMidX(), currentScene->getBoundingBox().size.height / 7);
    heroSpaceShip->setScale(0.3);
    currentScene->addChild(heroSpaceShip);
}

void Hero::MoveLeft(float delta)
{
    heroSpaceShip->setTexture("res/elonLeft.png");
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(-heroSpeed, 0)));
}

void Hero::MoveRight(float delta)
{
    heroSpaceShip->setTexture("res/elonRight.png");
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(heroSpeed, 0)));
}

void Hero::StopMoving()
{
    heroSpaceShip->setTexture("res/elonCenter.png");
}
