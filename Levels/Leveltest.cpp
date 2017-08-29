//
//  Leveltest.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Levels/Leveltest.h"

// constructor
LevelTest::LevelTest(float difficultyLevel, int nrEnemies):
levelStatus(true), difficultyLevel(difficultyLevel), nrEnemies(nrEnemies)
{
}

// destructor
LevelTest::~LevelTest()
{
    delete entitiesManager;
    delete inputManager;
}

// kind of constructor for level
bool LevelTest::init()
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
bool LevelTest::isLevelFinished()
{
    //return levelStatus;
    return false;
}

// update
void LevelTest::update(float delta)
{
    if(!entitiesManager->isHeroAlive() || entitiesManager->isEnemyAlive())
        levelStatus = false;
    
    if(levelStatus)
    {
        entitiesManager->update(delta);
        inputManager->update(delta);
    }
}
