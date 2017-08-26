//
//  ManagerEntities.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/26/17.
//
//

#include <stdio.h>
#include "Entities/ManagerEntities.h"

// constructor
ManagerEntities::ManagerEntities(cocos2d::Scene* aScene, int nrEnemies)
{
    currentScene = aScene;
    
    // create nr Enemies
    
    theHero = new Hero(currentScene);

}

// destructor
ManagerEntities::~ManagerEntities()
{
    // delete the hero
    delete theHero;
    
    // delete enemies
    delete enemiesContainer;
    
}

// update
void ManagerEntities::update(float delta)
{
    theHero -> update(delta);
    enemiesContainer -> update(delta);
}

// getter
Hero* ManagerEntities::getHero()
{
    return theHero;
}
