//
//  ManagerEnemies.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/EnemyContainer.h"

class ManagerEnemies
{
public:
    ManagerEnemies(int nrEnemies, float difficulty);
    
    void update(float delta);
    
private:
    
    // ai element
    
    unique_ptr<EnemyContainer> enemiesContainer;
};
