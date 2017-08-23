//
//  InputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include <algorithm>
#include <vector>
#include "cocos2d.h"
#include "InputControls/InputControl.h"
#include "InputControls/ManagerInputControls.h"

USING_NS_CC;
using namespace std;

// container class for input controls
class InputControls
{
public:
    // destructor
    virtual ~InputControls();
    
    void add(InputControl* ptr);
    
    void update(float delta);
    
    // there should be another class only for listeners
    
private:
    
    // TouchListener* touchListener; something like this
    vector<InputControl*> inputControlContainer;
};
