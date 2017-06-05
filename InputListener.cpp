
#include "InputListener.h"

InputListener::InputListener()
{
	touchListener = cocos2d::EventListenerTouchOneByOne::create();
	keyboardListener = cocos2d::EventListenerKeyboard::create();
}

cocos2d::EventListenerTouchOneByOne* InputListener::getTouch()
{
	return touchListener;
}

cocos2d::EventListenerKeyboard* InputListener::getKeyboard()
{
	return keyboardListener;
}