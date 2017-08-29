//
//  Projectile.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/6/17.
//
//

#pragma once
#include "cocos2d.h"
#include <algorithm>
#include <vector>
USING_NS_CC;
using namespace std;

// abstract class
class Projectile
{
public:
    // verifies collsion with another object(sprite)
    virtual bool collisionWithObject(cocos2d::Sprite* aSprite) = 0;
    
    // update movement and if update fails it returns false
    virtual bool isStillInViewArea() = 0;
    
    // destructor
    virtual ~Projectile() = default;
};
