//
//  InputControls.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "Header.h"
#include "InputControls/InputControl.h"

USING_NS_CC;
using namespace std;

// container class for input controls
class InputControls
{
public:
    
    // destructor
    ~InputControls();
    
    void add(InputControl* ptr);
    
    void update(float delta);
    
private:
    
    vector<InputControl*> inputControlContainer;
};
