//
//  Scenario.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Header.h"

// Different difficulties for the game

struct levelInit
{
    // simple constructor with member initializer list
    levelInit(float difficulty = 1, int nrEnemies = 3):difficulty(difficulty),nrEnemies(nrEnemies){}
    
    float difficulty;
    int nrEnemies;
};

class Scenario
{
public:
    void easyScenario();
    void mediumScenario();
    void hardScenario();
    
    levelInit nextLevelScenario();

private:
    deque<levelInit> scenarioContainer;
};

