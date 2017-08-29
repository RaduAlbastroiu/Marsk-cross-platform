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
    CREATE_FUNC(Level);
    // create scene
    static cocos2d::Scene* createScene();
    
    // destructor
    ~Level();
    
    // run
    virtual bool init() override;
    
    // update
    virtual void update(float delta) override;
    
    // is level Finished
    bool isLevelFinished();
    
    // set
    void setDifficulty(float diff);
    void setNrEnemies(int nr);
    
private:

    bool levelStatus;
    float difficultyLevel = 1;
    int nrEnemies = 1;
    
    ManagerEntities* entitiesManager;
    ManagerInputControls* inputManager;
    
};
