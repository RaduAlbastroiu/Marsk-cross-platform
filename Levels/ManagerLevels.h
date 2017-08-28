//
//  ManagerLevels.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Levels.h"
#include "Levels/FactoryLevels.h"

class ManagerLevels
{
public:
    
    // constructor
    ManagerLevels(Director* aDirectorRef);
    
    // destructor
    ~ManagerLevels() = default;
    
    // app start
    void start();
    
    // app paused
    void pause();
    
    // app relaunch
    void resume();
    
protected:
    
    // play a scene
    void runWithScene(cocos2d::Scene* aScene);
    
    cocos2d::Scene* currentRunningScene;
    unique_ptr<Level> currentLevel;
    
    unique_ptr<Levels> levelsContainer;
    
    Director* directorRef;
    
};
