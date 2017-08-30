//
//  ManagerLevels.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Level.h"
#include "Levels/FactoryLevel.h"
#include "Levels/CoordinatorLevel.h"

class MyDirector
{
public:
    
    // constructor
    MyDirector(Director* aDirectorRef);
    
    // destructor
    ~MyDirector() = default;
    
    // app start
    void start();
    
    // app paused
    void pause();
    
    // app relaunch
    void resume();
    
protected:
    
    // play a scene
    void runWithScene(cocos2d::Scene* aScene);
    
    FactoryLevel* currentFactory;
    CoordinatorLevel* coordinator;
    Director* directorRef;
    
};
