//
//  BuilderInputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/BuilderInputControls.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControlMovement.h"
#include "InputControls/InputControlProjectiles.h"
#include "Entities/Entity.h"

// constructor
BuilderInputControls::BuilderInputControls(cocos2d::Scene* aScene, Entity* aEntity)
{
    // create inputControls
    inputControls = new InputControls();
    
    // create other InputControls
    InputControl* move = new InputControlMovement(aScene, aEntity);
    InputControl* projectile = new InputControlProjectiles(aScene, aEntity);
    
    // add input Controls
    inputControls->add(move);
    inputControls->add(projectile);
}

// destructor
BuilderInputControls::~BuilderInputControls()
{
    delete inputControls;
}

// simple getter
InputControls* BuilderInputControls::getInputControls()
{
    return inputControls;
}
