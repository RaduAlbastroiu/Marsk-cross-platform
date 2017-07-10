//
//  BuilderInputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class BuilderInputControls
{
public:
    BuilderInputControls(cocos2d::Scene* aScene, Entity* aEntity);
    ~BuilderInputControls();
    
    InputControls* getInputControls();
    
    
private:
    InputControls* inputControls;
    
};
