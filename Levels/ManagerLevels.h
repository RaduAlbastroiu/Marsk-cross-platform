//
//  ManagerLevels.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Header.h"

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
    void contnue();
    
protected:
    
    // play a scene
    void runWithScene(cocos2d::Scene* aScene);
    
    Director* directorRef;
    
};
