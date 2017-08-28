//
//  FactoryLevels.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Levels/FactoryLevels.h"

/*
unique_ptr<Levels> FactoryLevels::create(unique_ptr<levelsInit> initList)
{
    auto levels = make_unique<Levels>();
    
    for(auto &levelInit : initList.get()->containerLevelDiff)
    {
        levels->addLevel(FactoryLevel::createLevel(levelInit));
    }
    
    return levels;
}
*/
