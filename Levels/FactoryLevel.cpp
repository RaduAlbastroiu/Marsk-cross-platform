//
//  FactoryLevel.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Levels/FactoryLevel.h"


FactoryLevel::FactoryLevel()
{
    // auto choice
    currentScenario = make_unique<Scenario>();
    createEasy();
}

cocos2d::Scene* FactoryLevel::createLevel()
{
    //auto elem = currentScenario->nextLevelScenario();
    auto lvl = Level::createScene();
    
    return lvl;
}

void FactoryLevel::createEasy()
{
    currentScenario->easyScenario();
}

void FactoryLevel::createMedm()
{
    currentScenario->mediumScenario();
}

void FactoryLevel::createHard()
{
    currentScenario->hardScenario();
}

