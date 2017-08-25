//
//  InputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#include <stdio.h>
#include "InputControls/InputControls.h"

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
