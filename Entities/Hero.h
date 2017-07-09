//
//  Hero.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "cocos2d.h"
#include "Entities/Entity.h"
USING_NS_CC;

class Hero : public Entity
{
public:
    Hero(cocos2d::Scene* scene, float speed);
    
    void MoveLeft(float delta);
    void MoveRight(float delta);
    void StopMoving();
    
private:
    void loadHeroSpaceship();
    
    float heroSpeed;
    cocos2d::Sprite* heroSpaceShip;
    cocos2d::Scene* currentScene;
};

