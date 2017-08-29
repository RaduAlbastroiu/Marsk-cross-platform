//
//  ProjectileEnemySimple.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/7/17.
//
//

#pragma once
#include "Projectiles/ProjectileEnemySimple.h"

// constructor
ProjectileEnemySimple::ProjectileEnemySimple(cocos2d::Scene* aScene, Sprite* aHeroSpaceShip, float aSpeed)
{
    // set the scene for this proiectile
    scene = aScene;
    // set speed
    speed = aSpeed;
    scale = 0.1;
    
    projectile = Sprite::create("res/laserRed.png");
    
    
    projectile->setScale(scale);
    projectile->setAnchorPoint(Vec2(0.5, 0.5));
    projectile->setPosition(Vec2(aHeroSpaceShip->getBoundingBox().getMidX(),
                                 aHeroSpaceShip->getBoundingBox().getMaxY() + projectile->getBoundingBox().size.height/2));
    
    projectile->runAction(MoveTo::create(aSpeed, Vec2(projectile->getBoundingBox().getMidX(),
                                                      scene->getBoundingBox().size.height + projectile->getBoundingBox().size.height + 1)));
    
    scene->addChild(projectile);
}

// destructor
ProjectileEnemySimple::~ProjectileEnemySimple()
{
    scene->removeChild(projectile);
}

// returns true if there is a collision
bool ProjectileEnemySimple::collisionWithObject(cocos2d::Sprite* aSprite)
{
    return projectile->boundingBox().intersectsRect(aSprite->boundingBox());
}

// returns false if the proiectile is out of sight
bool ProjectileEnemySimple::isStillInViewArea()
{
    return scene->getBoundingBox().intersectsRect(projectile->getBoundingBox());
}
