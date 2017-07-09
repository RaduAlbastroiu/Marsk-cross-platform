//
//  MovementHero.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <stdio.h>
#include "Movement/Movement.h"
#include "Movement/Move.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

Movement::Movement(cocos2d::Scene* aScene, cocos2d::Sprite* aEntity, float aSpeed):
speed(aSpeed), entity(aEntity), scene(aScene)
{}

void Movement::executeMove(Move* aMove)
{
    if(aMove == null)
    {
        StopMoving();
    }
    else
    {
        if(aMove->direction)
            MoveRight(aMove->delta);
        else
            MoveLeft(aMove->delta);
    }
}

void Movement::MoveLeft(float delta)
{
    entity->setTextureLeft();
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(-speed, 0)));
}

void Movement::MoveRight(float delta)
{
    entity->setTextureRight();
    heroSpaceShip->runAction(MoveBy::create(delta, Vec2(speed, 0)));
}

void Movement::StopMoving()
{
    entity->setTextureCenter;
}
