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
    
    virtual void setTextureCenter() override;
    virtual void setTextureLeft() override;
    virtual void setTextureRight() override;
    
private:
    vector<Entity*> entities;
};
