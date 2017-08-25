//
//  Entity.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "Entities/Entity.h"

using namespace std;

// update Entity
void Entity::update(float delta)
{
    // update Projectiles
    projectileEntity->update();
}
