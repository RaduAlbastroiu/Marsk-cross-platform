#pragma once

#include "cocos2d.h"

class AudioScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(AudioScene);

private:
	cocos2d::Sprite* sprite, *sprite2;
	cocos2d::Label* label;
};