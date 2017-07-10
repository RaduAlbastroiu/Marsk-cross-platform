//
//  InputControl.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#include <stdio.h>
#include "cocos2d.h"
#include "InputControls/InputControl.h"
#include "InputControls/InputControls.h"
#include "Entities/Entity.h"

// destructor
InputControl::~InputControl()
{
    delete currentEntity;
    delete workObject;
    delete currentScene;
}
