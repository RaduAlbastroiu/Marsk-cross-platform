//
//  FactoryLevel.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Level.h"
#include "Levels/Scenario.h"
#include "Levels/Coordinator.h"

class FactoryLevel
{
public:
    // constructor
    FactoryLevel();
    
    // create a level
    cocos2d::Scene* createLevel();
    
    void createEasy();
    void createMedm();
    void createHard();
    
private:
    unique_ptr<Scenario> currentScenario;
};
