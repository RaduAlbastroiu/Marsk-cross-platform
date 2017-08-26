//
//  InputControl.h
//  Marsk
//
//  Created by Albastroiu Radu on 7/10/17.
//
//

#pragma once
#include "Header.h"
#include "Entities/Hero.h"

USING_NS_CC;
using namespace std;

// abstract class
class InputControl
{
public:
    
    // virtual destructor
    virtual ~InputControl();
        
    virtual void update(float delta) = 0;

};
