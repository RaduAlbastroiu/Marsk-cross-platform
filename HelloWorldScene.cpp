#include "HelloWorldScene.h"

cocos2d::Scene* HelloWorld::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
	{
		return false;
	}

	label = cocos2d::Label::createWithSystemFont("Press space to pause all, 1 to pause left", "Arial", 30);
	label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));

	sprite = cocos2d::Sprite::create("laserGreen.png");
	sprite2 = cocos2d::Sprite::create("laserRed.png");
	sprite->setPosition(250, this->getBoundingBox().getMidY());
	sprite2->setPosition(700, this->getBoundingBox().getMidY());

	auto rotate = cocos2d::RotateBy::create(1, 45);
	auto rotate2 = cocos2d::RotateBy::create(1, -45);

	auto repeat1 = cocos2d::RepeatForever::create(rotate);
	auto repeat2 = cocos2d::RepeatForever::create(rotate2);

	this->addChild(label, 0);
	this->addChild(sprite, 0);
	this->addChild(sprite2, 0);

	sprite->runAction(repeat1);
	sprite2->runAction(repeat2);

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
		// On Spacebar, Pause/Unpause all actions and updates
		if (code == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
			if (pausedNodes.size()) {
				cocos2d::Director::getInstance()->getActionManager()->resumeTargets(pausedNodes);
				pausedNodes.clear();
				spritePaused = false; // In case user currently has 1 pressed too
			}
			else
				pausedNodes = cocos2d::Director::getInstance()->getActionManager()->pauseAllRunningActions();
			label->setString("Spacebar pressed");
		}

		// Pause/UnPause just sprite 1
		if (code == cocos2d::EventKeyboard::KeyCode::KEY_1) {
			if (spritePaused)
				sprite->resumeSchedulerAndActions();
			else
				sprite->pauseSchedulerAndActions();
			spritePaused = !spritePaused;
			label->setString("1 pressed");
		}
		
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}