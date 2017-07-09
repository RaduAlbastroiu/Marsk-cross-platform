//
//  Movement.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <stdio.h>
#include "Movement/Movement.h"

USING_NS_CC;
using namespace std;

Movement::Movement(cocos2d::Scene* aScene, Entity* aEntity, float aSpeed):
speed(aSpeed), entity(aEntity), scene(aScene)
{}
