//
//  Scenario.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#include <stdio.h>
#include "Levels/Scenario.h"


void Scenario::easyScenario()
{
    for(int i = 0; i < 9 ; i++)
    {
        scenarioContainer.push_back(levelInit(1,3));
    }
}

void Scenario::mediumScenario()
{
    for(int i = 0; i < 9 ; i++)
    {
        scenarioContainer.push_back(levelInit(0.8 + 0.2*i, i + 2));
    }
}

void Scenario::hardScenario()
{
    for(int i = 0; i < 9 ; i++)
    {
        scenarioContainer.push_back(levelInit(1 + 0.3*i, int(i * 1.5) + 5));
    }
}

levelInit Scenario::nextLevelScenario()
{
    auto elem = scenarioContainer.front();
    scenarioContainer.pop_front();
    return elem;
}
