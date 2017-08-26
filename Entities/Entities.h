//
//  Entities.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/Entity.h"

using namespace std;
USING_NS_CC;

class Entities
{
public:
    
    // destructor
    ~Entities();
    
    void update(float delta);
    
    void addEntity(Entity* aEntity);
    
    
private:
    vector<Entity*> entitiesContainer;
    
};
