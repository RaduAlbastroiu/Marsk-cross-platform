//
//  Level.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/ManagerEntities.h"
#include "InputControls/ManagerInputControls.h"

class Level : public cocos2d::Scene
{
public:
    
    // create scene
    cocos2d::Scene* createScene();
    
    // constructor
    Level(float difficultyLevel, int nrEnemies);
    
    // destructor
    ~Level();
    
    // run
    virtual bool init() override;
    
    // update
    virtual void update(float delta) override;
    
    // is level Finished
    bool isLevelFinished();
    
private:
    
    bool levelStatus;
    float difficultyLevel;
    int nrEnemies;
    
    ManagerEntities* entitiesManager;
    ManagerInputControls* inputManager;
};
