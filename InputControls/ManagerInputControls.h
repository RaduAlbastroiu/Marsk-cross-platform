//
//  BuilderInputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "InputControls/InputControls.h"
#include "InputControls/InputListener.h"
#include "cocos2d.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class ManagerInputControls
{
    
public:
    ManagerInputControls(cocos2d::Scene* aScene, Entity* aEntity);
    ~ManagerInputControls();
    
    void updateInputControls(float delta);
    
private:
    
    InputListener* inputListener;
    
    InputControls* inputControls;
    
};
