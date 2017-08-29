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
#include "Levels/Level.h"
#include "Levels/FactoryLevel.h"

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
    Level* currentLevel;
    FactoryLevel* currentFactory;
    
    Director* directorRef;
    
};
