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

Level* FactoryLevel::createLevel()
{
    auto elem = currentScenario->nextLevelScenario();
    return new Level(elem.difficulty, elem.nrEnemies);
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

