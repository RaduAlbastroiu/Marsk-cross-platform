//
//  Entities.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "Entities/Entities.h"

using namespace std;

// destructor
Entities::~Entities()
{
    for(auto it = entitiesContainer.begin(); it != entitiesContainer.end(); ++it)
    {
        delete (*it);
    }
    entitiesContainer.clear();
}

// update
void Entities::update(float delta)
{
    // update all entities
    for(auto& someEntity : entitiesContainer)
    {
        someEntity->update(delta);
    }
}

// if there is at least one surviving entity
bool Entities::areAlive()
{
    for(auto & entity : entitiesContainer)
        if(entity->isAlive())
            return true;
    
    return false;
}
