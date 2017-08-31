//
//  Background.cpp
//  Marsk
//
//  Created by Albastroiu Radu on 8/31/17.
//
//

#pragma once
#include "Levels/LevelBackground.h"

LevelBackground::LevelBackground(cocos2d::Scene* targetScene):
currentScene(targetScene)
{
    loadBackground();
    loadPlanetEarth();
    loadPlanetMars();
}

LevelBackground::~LevelBackground()
{
    currentScene->removeChild(background);
    currentScene->removeChild(planetEarth);
    currentScene->removeChild(planetMars);
}

void LevelBackground::loadBackground()
{
    background = cocos2d::Sprite::create("res/background.png");
    
    background->setAnchorPoint(Vec2(0.5, 0.5));
    background->setPosition(currentScene->getBoundingBox().getMidX(),
                            currentScene->getBoundingBox().getMidY());
    
    background->setScale(1);
    
    currentScene->addChild(background, 0);
}

void LevelBackground::loadPlanetEarth()
{
    planetEarth = cocos2d::Sprite::create("res/earth.png");

    planetEarth->setAnchorPoint(Vec2(0.5, 0.5));
    planetEarth->setPosition(currentScene->getBoundingBox().getMaxX(),
                             currentScene->getBoundingBox().getMinY());
    
    planetEarth->setScale(0.5);
    
    currentScene->addChild(planetEarth);
    
}

void LevelBackground::loadPlanetMars()
{
    planetMars = cocos2d::Sprite::create("res/mars.png");
    
    planetMars->setAnchorPoint(Vec2(0.5, 0.5));
    planetMars->setPosition(currentScene->getBoundingBox().getMinX(),
                             currentScene->getBoundingBox().getMaxY());
    
    planetMars->setScale(0.5);
    
    currentScene->addChild(planetMars);
    
}

void LevelBackground::update(float delta)
{
    // do nothing yet
    // maybe rotate the planets
}
