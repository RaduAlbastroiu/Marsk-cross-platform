//
//  FactoryLevels.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Levels.h"
#include "Levels/Scenario.h"
#include "Levels/FactoryLevel.h"


class FactoryLevels
{
    static unique_ptr<Levels> create(unique_ptr<levelsInit> initList);
    
public:
    static unique_ptr<Levels> createEasy();
    static unique_ptr<Levels> createMedm();
    static unique_ptr<Levels> createHard();
};
