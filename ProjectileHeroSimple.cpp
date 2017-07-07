//
//  ProiectileHeroSimple.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/5/17.
//
//

#include "ProjectileHeroSimple.h"

// constructor
ProjectileHeroSimple::ProjectileHeroSimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed, float aScale)
{
    // set the scene for this proiectile
    scene = aScene;
    // set speed
    speed = aSpeed;
    
    projectile = Sprite::create("res/laserGreen.png");
    
    
    projectile->setScale(aScale);
    projectile->setAnchorPoint(Vec2(0.5, 0.5));
    projectile->setPosition(Vec2(aHeroSpaceShip->getBoundingBox().getMidX(),
                             aHeroSpaceShip->getBoundingBox().getMaxY() + projectile->getBoundingBox().size.height/2));
    
    projectile->runAction(MoveTo::create(aSpeed, Vec2(projectile->getBoundingBox().getMidX(),
                                                           scene->getBoundingBox().size.height + projectile->getBoundingBox().size.height + 1)));
    
    scene->addChild(projectile);
}

// destructor
ProjectileHeroSimple::~ProjectileHeroSimple()
{
    scene->removeChild(projectile);
}

// returns true if there is a collision
bool ProjectileHeroSimple::collisionWithObject(cocos2d::Sprite* aSprite)
{
    return projectile->boundingBox().intersectsRect(aSprite->boundingBox());
}

// returns false if the proiectile is out of sight
bool ProjectileHeroSimple::isStillInViewArea()
{
    return scene->getBoundingBox().intersectsRect(projectile->getBoundingBox());
}
