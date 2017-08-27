//
//  Levels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels.h"

// destructor
Levels::~Levels()
{
    for( auto it = levelContainer.begin(); it != levelContainer.end(); ++it)
        delete (*it);
    
    levelContainer.clear();
}

// add level
void Levels::addLevel(cocos2d::Scene* aLevelScene)
{
    levelContainer.push_back(dynamic_cast<Level*>(aLevelScene));
}

// next scene
cocos2d::Scene* Levels::nextLevel()
{
    cocos2d::Scene* nextScene = nullptr;
    
    if(levelContainer.size())
    {
        nextScene = levelContainer.front();
        levelContainer.pop_front();
    }
    
    return nextScene;
}
