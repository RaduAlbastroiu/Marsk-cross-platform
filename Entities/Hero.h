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
#include "Movement/Movement.h"

USING_NS_CC;
using namespace std;

class Hero : public Entity
{
public:
    Hero(cocos2d::Scene* scene, float speed);
    ~Hero();
    
    void setTextureCenter() override;
    void setTextureLeft() override;
    void setTextureRight() override;

private:
    
    void loadHeroSpaceship();
    
    cocos2d::Sprite* heroSpaceShip;
    cocos2d::Scene* currentScene;
};

