#pragma once

#include "cocos2d.h"
#include "InputListener.h"

class Intro : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(Intro);

private:
	void loadMenuNewGame();
	void loadMenuQuit();
	void loadMarsk();
	void loadBackGround();
	void loadPlanetEarth();
	void loadPlanetMars();
	void nextScene(cocos2d::Ref* pSender);
	void menuCloseCallback(cocos2d::Ref* pSender);

	cocos2d::MenuItemImage* newGameMenu;
	cocos2d::MenuItemImage* quitMenu;
	cocos2d::Sprite* backGround;
	cocos2d::Sprite* earth;
	cocos2d::Sprite* mars;
	cocos2d::Sprite* marsk;
};