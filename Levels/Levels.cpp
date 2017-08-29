//
//  Levels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/Levels.h"

// constructor
Levels::Levels(Level* aLevelScene)
{
    addLevel(aLevelScene);
}

// destructor
Levels::~Levels()
{
    levelContainer.clear();
}

// add level
void Levels::addLevel(Level* aLevelScene)
{
    levelContainer.push_back(aLevelScene);
}

// next scene
cocos2d::Scene* Levels::nextLevel()
{
    Level* nextLevel = nullptr;
    
    if(levelContainer.size())
    {
        // from unique to pointer
        nextLevel = levelContainer.front();
        levelContainer.pop_front();
    }
    
    return nextLevel->createScene();
}
