//
//  EnemyContainer.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Entities/EnemyContainer.h"

EnemyContainer::~EnemyContainer()
{
    enemyContainer.clear();
}

void EnemyContainer::addEnemy(unique_ptr<Enemy> aEnemy)
{
    enemyContainer.emplace_back(move(aEnemy));
}

void EnemyContainer::update(float delta)
{
    // remove enemies that are dead
    enemyContainer.erase(
                         remove_if(enemyContainer.begin(), enemyContainer.end(),
                                         [](const auto & aEnemy) {
                                             return aEnemy->isAlive() == false; }),
                         enemyContainer.end());

    // update alive enemies
    for(auto &enemy : enemyContainer)
    {
        enemy->update(delta);
        // update position
    }
}
