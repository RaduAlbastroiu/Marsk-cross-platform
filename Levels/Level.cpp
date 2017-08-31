//
//  Level.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/Level.h"

// create Scene
cocos2d::Scene * Level::createScene()
{
    return Level::create();
}

// destructor
Level::~Level()
{
    delete entitiesManager;
    delete inputManager;
    delete background;
    
    this->removeAllChildren();
}

// kind of constructor for level
bool Level::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    // add background stuff
    background = new LevelBackground(this);
    // create entities
    entitiesManager = new ManagerEntities(this, nrEnemies);
    // create input control
    inputManager = new ManagerInputControls(this, entitiesManager->getHero());
    
    this->scheduleUpdate();
    
    return true;
}

// update
void Level::update(float delta)
{
    entitiesManager->update(delta);
    inputManager->update(delta);
    background->update(delta);
    
    // level status update
    if(entitiesManager->isHeroAlive() == false)
        this->loseNextScene();
    
    if(entitiesManager->isEnemyAlive() == false)
        this->winNextScene();
    
}

void Level::winNextScene()
{
    Director::getInstance()->replaceScene(coordinator->winNext());
}

void Level::loseNextScene()
{
    Director::getInstance()->replaceScene(coordinator->loseNext());
}

// set dif
void Level::setDifficulty(float diff)
{
    difficultyLevel = diff;
}

// set nrEnemies
void Level::setNrEnemies(int nr)
{
    nrEnemies = nr;
}

void Level::setCoorinator(Coordinator* coordinator)
{
    this->coordinator = coordinator;
}
