//
//  Scenario.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#include <stdio.h>
#include "Levels/Scenario.h"


unique_ptr<levelsInit> Scenario::easyScenario()
{
    vector<levelInit> easy;
    for(int i = 0; i < 9 ; i++)
    {
        easy.emplace_back(levelInit());
    }
    
    return move(make_unique<levelsInit>(easy));
}


unique_ptr<levelsInit> Scenario::mediumScenario()
{
    vector<levelInit> medium;
    for(int i = 0; i < 9 ; i++)
    {
        medium.emplace_back(levelInit(0.8 + 0.2*i, i + 2));
    }
    
    return move(make_unique<levelsInit>(medium));
}

unique_ptr<levelsInit> Scenario::hardScenario()
{
    vector<levelInit> hard;
    for(int i = 0; i < 9 ; i++)
    {
        hard.emplace_back(levelInit(1 + 0.3*i, int(i * 1.5) + 5));
    }
    
    return move(make_unique<levelsInit>(hard));
}
