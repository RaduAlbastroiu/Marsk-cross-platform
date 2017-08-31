//
//  Background.h
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Header.h"

class LevelBackground
{
public:
    
    LevelBackground(cocos2d::Scene* targetScene);
    ~LevelBackground();
    
    void loadBackground();
    void loadPlanetEarth();
    void loadPlanetMars();
    
    void update(float delta);
    
private:
    
    cocos2d::Scene* currentScene;
    
    cocos2d::Sprite* background;
    cocos2d::Sprite* planetEarth;
    cocos2d::Sprite* planetMars;
};
