//
//  Entities.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <algorithm>
#include <vector>
#include "cocos2d.h"
#include "Entities/Entity.h"

using namespace std;
USING_NS_CC;

class Entities
{
public:
    
    void update(float delta);
    
    void addEntity(Entity* aEntity);
    
    
private:
    vector<Entity*> entitiesContainer;
    
};
