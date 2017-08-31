//
//  EnemyContainer.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/Enemy.h"

class EnemyContainer
{
public:
    ~EnemyContainer();
    
    void addEnemy(unique_ptr<Enemy> aEnemy);
    void update(float delta);
    
private:
    
    vector<unique_ptr<Enemy>> enemyContainer;
};
