//
//  InputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControl.h"
#include "InputControls/BuilderInputControls.h"
#include <algorithm>
#include <vector>

USING_NS_CC;
using namespace std;

class InputControls
{
public:
    // destructor
    virtual ~InputControls();
    
    void add(InputControl* ptr);
    
private:
    vector<InputControl*> inputControlContainer;
};
