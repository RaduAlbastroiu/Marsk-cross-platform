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

// run level
bool Level::init()
{
    entitiesManager = new ManagerEntities(this, nrEnemies);
    inputManager = new ManagerInputControls(this, entitiesManager->getHero());
    // create enemies
    
    this->scheduleUpdate();
    
    return true;
}

// is level finished
bool Level::isLevelFinished()
{
    return levelStatus;
}
