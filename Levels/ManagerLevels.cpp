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
ManagerLevels::ManagerLevels(Director* aDirectorRef):
directorRef(aDirectorRef)
{
    // build all the scenes
    // then take them one by one
    currentRunningScene = levelsContainer->nextLevel();
    currentLevel = dynamic_cast<Level*>(currentRunningScene);
}

// app start
void ManagerLevels::start()
{
    // manage scenes here
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
