//
//  MovementHero.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Entity.h"
#include "Movement/Movement.h"
#include "Movement/Move.h"

USING_NS_CC;
using namespace std;

class MovementHero : public Movement
{
public:
    Movement(cocos2d::Scene* aScene, cocos2d::Sprite* aEntity, float aSpeed);
    
    virtual void executeMove(Move* aMove) overide;
    virtual void MoveLeft(float delta);
    virtual void MoveRight(float delta);
    virtual void StopMoving();
    
    
};
