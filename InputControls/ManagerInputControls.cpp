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
#include "InputControls/ManagerInputControls.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControlMovementArrows.h"
#include "InputControls/InputControlProjectiles.h"
#include "Entities/Entity.h"

// constructor
ManagerInputControls::ManagerInputControls(cocos2d::Scene* aScene, Entity* aEntity)
{
    // create inputControls
    inputControls = new InputControls();
    
    // create other InputControls
    InputControl* move = dynamic_cast<InputControl*>(new InputControlMovementArrows(aScene, aEntity));
    InputControl* projectile = dynamic_cast<InputControl*>(new InputControlProjectiles(aScene, aEntity));
    
    // add input Controls
    inputControls->add(move);
    inputControls->add(projectile);
}

// destructor
ManagerInputControls::~ManagerInputControls()
{
    delete inputControls;
}

// update 
void ManagerInputControls::updateInputControls(float delta)
{
    inputControls->update(delta);
}
