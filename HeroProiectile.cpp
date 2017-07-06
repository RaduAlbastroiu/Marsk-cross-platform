//
//  HeroProiectile.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "HeroProiectile.h"

HeroProiectile::HeroProiectile(cocos2d::Scene* scene, Sprite* heroSpaceShip, float speed, float scale)
{
    auto bullet = Sprite::create("res/laserGreen.png");
    
    bullet->setScale(scale);
    bullet->setAnchorPoint(Vec2(0.5, 0.5));
    bullet->setPosition(Vec2(heroSpaceShip->getBoundingBox().getMidX(),
                             heroSpaceShip->getBoundingBox().getMaxY() + bullet->getBoundingBox().size.height/2));
    
    bullet->runAction(MoveTo::create(speed, Vec2(bullet->getBoundingBox().getMidX(),
                                                           scene->getBoundingBox().size.height + bullet->getBoundingBox().size.height + 1)));
}
