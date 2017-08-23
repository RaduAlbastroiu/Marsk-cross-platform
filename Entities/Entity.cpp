//
//  Entity.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <stdio.h>
#include "Entities/Entity.h"
#include "Entities/Entities.h"

using namespace std;

// update Entity
void Entity::update(float delta)
{
    // update Projectiles
    projectileEntity->update();
}
