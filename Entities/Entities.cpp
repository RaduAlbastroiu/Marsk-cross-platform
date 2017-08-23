//
//  Entities.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <stdio.h>
#include "cocos2d.h"
#include "Entities/Entities.h"
#include "Entities/Entity.h"

using namespace std;

// update
void Entities::update(float delta)
{
    // update all entities
    for(auto& someEntity : entitiesContainer)
    {
        someEntity->update(delta);
    }
}
