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
}

// kind of constructor for level
bool Level::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    // create entities
    entitiesManager = new ManagerEntities(this, nrEnemies);
    // create input control
    inputManager = new ManagerInputControls(this, entitiesManager->getHero());
    
    // add background stuff !!!!
    
    this->scheduleUpdate();
    
    return true;
}

// update
void Level::update(float delta)
{
    entitiesManager->update(delta);
    inputManager->update(delta);
    
    // level status update
    if(entitiesManager->isHeroAlive() == false)
        loseNextScene();
    
    if(entitiesManager->isEnemyAlive() == false)
        winNextScene();
    
}

void Level::winNextScene()
{
    Director::getInstance()->replaceScene(winScene);
}

void Level::loseNextScene()
{
    Director::getInstance()->replaceScene(loseScene);
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

void Level::setNextWinScene(cocos2d::Scene* nextScene)
{
    winScene = nextScene;
}

void Level::setNextLoseScene(cocos2d::Scene* nextScene)
{
    loseScene = nextScene;
}
