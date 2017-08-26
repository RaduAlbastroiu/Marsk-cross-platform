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
}

// app start
void ManagerLevels::start()
{
    // manage scenes here
}

// app paused
void pause()
{
    // put everything on pause
}

// app relaunch
void contnue()
{
    // reload from last scene
}


// play a scene
void ManagerLevels::runWithScene(cocos2d::Scene* aScene)
{
    directorRef->runWithScene(aScene);
}
