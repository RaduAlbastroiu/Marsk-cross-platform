//
//  InputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include "cocos2d.h"
#include "InputControls/InputControls.h"


// destructor
InputControls::~InputControls()
{
    inputControlContainer.clear();
}

// add a new type of inputControl
void InputControls::add(InputControl* ptr)
{
    inputControlContainer.push_back(ptr);
}

// update
void InputControls::update(float delta)
{
    // update all input controls
    for(auto &someInputControl : inputControlContainer)
    {
        someInputControl->update(delta);
    }
}
