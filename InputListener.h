#pragma once

#include "cocos2d.h"

class InputListener
{
public:
	InputListener();

	cocos2d::EventListenerTouchOneByOne* getTouch();
	cocos2d::EventListenerKeyboard* getKeyboard();

private:
	cocos2d::EventListenerTouchOneByOne* touchListener;
	cocos2d::EventListenerKeyboard* keyboardListener;
};