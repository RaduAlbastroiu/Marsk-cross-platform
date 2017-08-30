//
//  CoordinatorLevel.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/30/17.
//
//

#pragma once
#include "Header.h"
#include "Levels/Coordinator.h"
#include "Levels/FactoryLevel.h"

// win/lose scenes for a level
class CoordinatorLevel : public Coordinator
{
public:
    // create with factory
    CoordinatorLevel(FactoryLevel* factory);
    
    cocos2d::Scene* winNext() override;
    cocos2d::Scene* loseNext() override;
    
private:
    
    FactoryLevel* factory;
};
