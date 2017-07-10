//
//  InputControls.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include <algorithm>
#include <vector>


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
