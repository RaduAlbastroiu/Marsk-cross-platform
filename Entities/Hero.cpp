//
//  Hero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "Entities/Hero.h"
#include "Movement/Movement.h"
#include "Movement/MovementHero.h"
#include "InputControls/InputControls.h"

Hero::Hero(cocos2d::Scene* scene, InputControls* controls, float speed)
{
    // create new movement object
    moveWorker = new MovementHero(currentScene, this, speed);
    // asign movement object
    inputControl = new InputControls(currentScene);
    
    currentScene = scene;
    loadHeroSpaceship();
}

Hero::~Hero()
{
    delete moveWorker;
}


void Hero::loadHeroSpaceship()
{
    heroSpaceShip = cocos2d::Sprite::create("res/elonBack.png");
    heroSpaceShip->setAnchorPoint(Vec2(0.5, 0.5));
    heroSpaceShip->setPosition(currentScene->getBoundingBox().getMidX(), currentScene->getBoundingBox().size.height / 7);
    heroSpaceShip->setScale(0.3);
    currentScene->addChild(heroSpaceShip);
}
