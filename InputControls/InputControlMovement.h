//
//  InputControlMovement.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "cocos2d.h"
#include "InputControls/InputControls.h"
#include "InputControls/InputControl.h"
#include "Entities/Entity.h"

USING_NS_CC;
using namespace std;

class InputControlMovement : public InputControl
{
    
public:
    InputControlMovement();
    virtual ~InputControlMovement() = default;
    
};
