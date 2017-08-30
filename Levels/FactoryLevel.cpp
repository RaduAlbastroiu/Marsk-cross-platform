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
    auto sc = dynamic_cast<Level*>(lvl);
    if(sc)
    {
        auto scene = currentScenario->nextLevelScenario();
        sc->setDifficulty(scene.difficulty);
        sc->setNrEnemies(scene.nrEnemies);
    }

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

