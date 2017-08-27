//
//  Level.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/Level.h"

// constructor
Level::Level(float difficultyLevel, int nrEnemies):
levelStatus(true), difficultyLevel(difficultyLevel), nrEnemies(nrEnemies)
{
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
    // create entities
    entitiesManager = new ManagerEntities(this, nrEnemies);
    // create input control
    inputManager = new ManagerInputControls(this, entitiesManager->getHero());
    
    // add background stuff !!!!
    
    this->scheduleUpdate();
    
    return true;
}

// is level finished
bool Level::isLevelFinished()
{
    //return levelStatus;
    return false;
}

// update
void Level::update(float delta)
{
    if(!entitiesManager->isHeroAlive() || entitiesManager->isEnemyAlive())
        levelStatus = false;
    
    if(levelStatus)
    {
        entitiesManager->update(delta);
        inputManager->update(delta);
    }
}
