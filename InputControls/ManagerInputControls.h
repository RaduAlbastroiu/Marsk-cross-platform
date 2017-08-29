//
//  BuilderInputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "Header.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputListener.h"

USING_NS_CC;
using namespace std;

class ManagerInputControls
{
    
public:
    ManagerInputControls(cocos2d::Scene* aScene, Hero* aEntity);
    ~ManagerInputControls();
    
    void update(float delta);
    
    
private:
    
    InputListener* inputListener;
    
    InputControls* inputControls;
    
};
