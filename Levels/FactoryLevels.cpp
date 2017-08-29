//
//  FactoryLevels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Levels/FactoryLevels.h"

int FactoryLevels::levelsCreated = 0;

unique_ptr<Levels> FactoryLevels::create(unique_ptr<levelsInit> initList)
{
    auto levels = make_unique<Levels>();
    
    for(auto &levelInit : initList.get()->containerLevelDiff)
    {
        levels->addLevel(FactoryLevel::createLevel(levelInit));
    }
    
    return levels;
}

unique_ptr<Levels> FactoryLevels::createEasy()
{
    return create(Scenario::easyScenario());
}

unique_ptr<Levels> FactoryLevels::createMedm()
{
    return create(Scenario::mediumScenario());
}
unique_ptr<Levels> FactoryLevels::createHard()
{
    return create(Scenario::hardScenario());
}
