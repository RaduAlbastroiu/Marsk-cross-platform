//
//  CoordinatorLevel.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/30/17.
//
//

#pragma once
#include "Levels/CoordinatorLevel.h"

CoordinatorLevel::CoordinatorLevel(FactoryLevel* factory)
:factory(factory)
{
}

cocos2d::Scene* CoordinatorLevel::winNext()
{
    auto ptr = factory->createLevel();
    auto sc = dynamic_cast<Level*>(ptr);
    if(sc)
    {
        sc->setCoorinator(this);
    }

    return ptr;
}

cocos2d::Scene* CoordinatorLevel::loseNext()
{
    // not good this should be a cut scene
    return factory->createLevel();
}
