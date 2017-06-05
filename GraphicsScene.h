#pragma once

#include "cocos2d.h"

class GraphicsScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GraphicsScene);
	void menuCloseCallback(cocos2d::Ref* pSender);
};