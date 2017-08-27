//
//  BuilderInputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "InputControls/ManagerInputControls.h"
#include "InputControls/InputControlMovementArrows.h"
#include "InputControls/InputControlProjectiles.h"

// constructor
ManagerInputControls::ManagerInputControls(cocos2d::Scene* aScene, Hero* aEntity)
{
    // create inputControls
    inputControls = new InputControls();
    
    // create other InputControls
    InputControl* move = dynamic_cast<InputControl*>(new InputControlMovementArrows(aScene, aEntity));
    InputControl* projectile = dynamic_cast<InputControl*>(new InputControlProjectiles(aScene, aEntity));
    
    // add input Controls
    inputControls->add(move);
    inputControls->add(projectile);
    
    // create input listener
    inputListener = new InputListener(static_cast<InputControlMovementArrows*>(move), static_cast<InputControlProjectiles*>(projectile));
    
    // add input listener to the scene
    aScene->addChild(inputListener);
    
}

// destructor
ManagerInputControls::~ManagerInputControls()
{
    delete inputListener;
    delete inputControls;
}

// update 
void ManagerInputControls::update(float delta)
{
    inputControls->update(delta);
}
