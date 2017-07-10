//
//  Move.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 7/9/17.
//
//

#pragma once
#include <stdio.h>
#include "Movement/Move.h"

Move::Move(bool aDirection, float aDelta):
direction(aDirection), delta(aDelta)
{}

bool Move::MoveLeft()
{
    if( direction )
        return false;
    return true;
}

bool Move::MoveRight()
{
    if( direction )
        return true;
    return false;
}

float Move::getDelta()
{
    return delta;
}
