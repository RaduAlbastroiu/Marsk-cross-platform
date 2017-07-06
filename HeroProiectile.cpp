//
//  HeroProiectile.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "HeroProiectile.h"

// constructor
HeroProiectile::HeroProiectile(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    // set the scene for this proiectile
    scene = aScene;
    // set speed
    speed = aSpeed;
    
    proiectile = Sprite::create("res/laserGreen.png");
    
    
    proiectile->setScale(aScale);
    proiectile->setAnchorPoint(Vec2(0.5, 0.5));
    proiectile->setPosition(Vec2(aHeroSpaceShip->getBoundingBox().getMidX(),
                             aHeroSpaceShip->getBoundingBox().getMaxY() + proiectile->getBoundingBox().size.height/2));
    
    proiectile->runAction(MoveTo::create(aSpeed, Vec2(proiectile->getBoundingBox().getMidX(),
                                                           scene->getBoundingBox().size.height + proiectile->getBoundingBox().size.height + 1)));
    
    scene->addChild(proiectile);
}

// destructor
HeroProiectile::~HeroProiectile()
{
    scene->removeChild(proiectile);
}

// returns true if there is a collision
bool HeroProiectile::collisionWithObject(cocos2d::Sprite* aSprite)
{
    return proiectile->boundingBox().intersectsRect(aSprite->boundingBox());
}

// returns false if the proiectile is out of sight
bool HeroProiectile::isStillInViewArea()
{
    return scene->getBoundingBox().intersectsRect(proiectile->getBoundingBox());
}
