//
//  Entities.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Entity.h"
#include <algorithm>
#include <vector>
using namespace std;
USING_NS_CC;

class Entities
{
public:
    virtual void addEntity() = 0;
    
private:
    vector<Entity*> entities;
};
