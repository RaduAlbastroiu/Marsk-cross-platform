//
//  Levels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/Levels.h"

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
    cocos2d::Scene* nextScene = nullptr;
    
    if(levelContainer.size())
    {
        // from unique to pointer
        nextScene = levelContainer.front();
        levelContainer.pop_front();
    }
    
    return nextScene;
}
