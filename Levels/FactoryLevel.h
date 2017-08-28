//
//  FactoryLevel.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/28/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Level.h"
#include "Levels/Scenario.h"


class FactoryLevel
{
public:
    // create a level
    static Level* createLevel(levelInit& init);
    
private:
    
};
