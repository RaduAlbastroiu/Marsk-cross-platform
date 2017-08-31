//
//  ManagerEntities.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/Entities.h"
#include "Entities/Hero.h"

class ManagerEntities
{
public:
    // constructor
    ManagerEntities(cocos2d::Scene* aScene, int nrEnemies, float difficulty);
    
    // destructor
    ~ManagerEntities();
    
    // update
    void update(float delta);
    
    // getter
    Hero* getHero();
    
    bool isHeroAlive();
    bool isEnemyAlive();
    
private:
    
    Entities* enemiesContainer;
    Hero* theHero;
    
    cocos2d::Scene* currentScene;
    
};

