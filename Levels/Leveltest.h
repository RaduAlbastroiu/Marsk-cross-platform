//
//  Leveltest.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/ManagerEntities.h"
#include "InputControls/ManagerInputControls.h"

class LevelTest : public cocos2d::Scene
{
public:
    
    // constructor
    LevelTest(float difficultyLevel, int nrEnemies);
    
    // destructor
    ~LevelTest();
    
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
