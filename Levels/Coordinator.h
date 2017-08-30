//
//  Coordinator.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/30/17.
//
//

#pragma once
#include "Header.h"

class Coordinator
{
public:
    virtual ~Coordinator() = default;
    
    virtual cocos2d::Scene* winNext() = 0;
    virtual cocos2d::Scene* loseNext() = 0;
    
};
