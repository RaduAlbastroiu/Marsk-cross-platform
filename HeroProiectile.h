//
//  HeroProiectile.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#pragma once
#include "cocos2d.h"
USING_NS_CC;

class HeroProiectile : public cocos2d::Sprite
{
public:
    HeroProiectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed, float scale);
    cocos2d::Sprite* GetProiectile();
    
private:
    cocos2d::Sprite* proiectile;
    
};
