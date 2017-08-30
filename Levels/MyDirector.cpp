//
//  ManagerLevels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Levels/MyDirector.h"

// constructor
MyDirector::MyDirector(Director* aDirectorRef)
{
    directorRef = aDirectorRef;
    currentFactory = new FactoryLevel();
    coordinator = new CoordinatorLevel(currentFactory);
}

// app start
void MyDirector::start()
{
    // manage first scene here
    auto firstScene = currentFactory->createLevel();
    auto sc = dynamic_cast<Level*>(firstScene);
    if(sc)
    {
        sc->setCoorinator(coordinator);
    }
    
    directorRef->runWithScene(firstScene);
}

// app paused
void MyDirector::pause()
{
    // put everything on pause
    directorRef->pause();
}

// app relaunch
void MyDirector::resume()
{
    // reload from last scene
    directorRef->resume();
}

// play a scene
void MyDirector::runWithScene(cocos2d::Scene* aScene)
{
    directorRef->replaceScene(aScene);
}
