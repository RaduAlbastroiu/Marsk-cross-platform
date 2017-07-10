//
//  Movement.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Entities.h"
#include "Entities/Entity.h"
#include "Movement/Move.h"

USING_NS_CC;
using namespace std;

class Movement
{
public:
    Movement(cocos2d::Scene* aScene, Entity* aEntity, float aSpeed);
    
    virtual void executeMove(Move* aMove) = 0;
    
protected:
    
    virtual void MoveLeft(float delta) = 0;
    virtual void MoveRight(float delta) = 0;
    virtual void StopMoving() = 0;
    
    float speed;
    
    Entity* entity;
    cocos2d::Scene* scene;
    
};
