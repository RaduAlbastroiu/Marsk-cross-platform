//
//  InputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "InputControls/InputControls.h"

// destructor
InputControls::~InputControls()
{
    for(auto it = inputControlContainer.begin(); it != inputControlContainer.end(); it++)
        delete (*it);
    
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
