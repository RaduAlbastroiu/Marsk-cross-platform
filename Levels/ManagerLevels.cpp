//
//  ManagerLevels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/ManagerLevels.h"

// constructor
ManagerLevels::ManagerLevels(Director* aDirectorRef)
{
    directorRef = aDirectorRef;
    
    //levelsContainer = FactoryLevels::create(move(Scenario::easyScenario()));
    
    currentRunningScene = levelsContainer->nextLevel();
}

// app start
void ManagerLevels::start()
{
    // manage scenes here
    if(currentRunningScene == nullptr)
        directorRef->end();
    
    directorRef->runWithScene(currentRunningScene);
}

// app paused
void ManagerLevels::pause()
{
    // put everything on pause
    directorRef->pause();
}

// app relaunch
void ManagerLevels::resume()
{
    // reload from last scene
    directorRef->resume();
}

// play a scene
void ManagerLevels::runWithScene(cocos2d::Scene* aScene)
{
    directorRef->replaceScene(aScene);
}
