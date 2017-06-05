#include "Intro.h"
#include "Level1Scene.h"

USING_NS_CC;

cocos2d::Scene * Intro::createScene()
{
	return Intro::create();
}

bool Intro::init()
{
	if (!Scene::init())
	{
		return false;
	}

	this->loadBackGround();
	this->loadPlanetEarth();
	this->loadPlanetMars();
	this->loadMarsk();
	this->loadMenuNewGame();
	this->loadMenuQuit();

	return true;
}

void Intro::loadMarsk()
{
	marsk = cocos2d::Sprite::create("marsk.png");
	marsk->setScale(0.8);
	marsk->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	marsk->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY() + marsk->getBoundingBox().size.height * 1.1);
	cocos2d::log("marsk sprite loaded");

	this->addChild(marsk);
}

void Intro::loadMenuNewGame()
{
	// new game sprite
	newGameMenu = cocos2d::MenuItemImage::create("start_on.png", "start_off.png", CC_CALLBACK_1(Intro::nextScene, this));
	newGameMenu->setScale(0.8);
	newGameMenu->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	newGameMenu->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	cocos2d::log("new game menu loaded");

	auto newGame = Menu::create(newGameMenu, NULL);
	newGame->setPosition(Vec2::ZERO);
	this->addChild(newGame);

}

void Intro::loadMenuQuit()
{
	// quit game sprite
	quitMenu = cocos2d::MenuItemImage::create("quit_on.png", "quit_off.png", CC_CALLBACK_1(Intro::menuCloseCallback, this));
	quitMenu->setScale(0.8);
	quitMenu->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	quitMenu->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY() - quitMenu->getBoundingBox().size.height);
	cocos2d::log("quit game menu loaded");

	auto quit = Menu::create(quitMenu, NULL);
	quit->setPosition(Vec2::ZERO);
	this->addChild(quit);

}

void Intro::loadBackGround()
{
	backGround = cocos2d::Sprite::create("background.png");

	double scaleX = double(Director::getInstance()->getVisibleSize().width) / double(backGround->getBoundingBox().size.width);
	double scaleY = double(Director::getInstance()->getVisibleSize().height) / double(backGround->getBoundingBox().size.height);

	double scaleMax = (scaleX > scaleY)? scaleX:scaleY;
	
	backGround->setAnchorPoint(Vec2(0.5, 0.5));
	backGround->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	backGround->setScale(scaleMax);

	cocos2d::log("Intro background loaded at scale %f", scaleMax);

	this->addChild(backGround, 0);
}

void Intro::loadPlanetEarth()
{
	// loading earth
	earth = cocos2d::Sprite::create("earth.png");

	double scaleX = double(Director::getInstance()->getVisibleSize().width) / double(earth->getBoundingBox().size.width);
	double scaleY = double(Director::getInstance()->getVisibleSize().height) / double(earth->getBoundingBox().size.height);

	double scaleMax = (scaleX > scaleY) ? scaleX / 2 : scaleY / 2;

	earth->setAnchorPoint(Vec2(0.5, 0.5));
	earth->setPosition(this->getBoundingBox().getMaxX(), this->getBoundingBox().getMinY());
	earth->setScale(scaleMax);

	cocos2d::log("Intro planet earth loaded at scale %f", scaleMax);

	this->addChild(earth);
}

void Intro::loadPlanetMars()
{
	// loading mars
	mars = cocos2d::Sprite::create("mars.png");

	double scaleX = double(Director::getInstance()->getVisibleSize().width) / double(mars->getBoundingBox().size.width);
	double scaleY = double(Director::getInstance()->getVisibleSize().height) / double(mars->getBoundingBox().size.height);

	double scaleMax = (scaleX > scaleY) ? scaleX / 2 : scaleY / 2;

	mars->setAnchorPoint(Vec2(0.5, 0.5));
	mars->setPosition(this->getBoundingBox().getMinX(), this->getBoundingBox().getMaxY());
	mars->setScale(scaleMax);

	cocos2d::log("Intro planet earth loaded at scale %f", scaleMax);

	this->addChild(mars);
}

void Intro::menuCloseCallback(Ref* pSender)
{
	cocos2d::Director::getInstance()->end();
}

void Intro::nextScene(cocos2d::Ref* pSender)
{
	auto level1 = Level1Scene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.5, level1));
}