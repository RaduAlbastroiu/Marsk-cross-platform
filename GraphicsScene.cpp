#include "GraphicsScene.h"

USING_NS_CC;

Scene* GraphicsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GraphicsScene::create();
	scene->addChild(layer);

	return scene;
}

bool GraphicsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sprite = Sprite::create("gameGrid.png");
	auto sprite2 = Sprite::create("gameBlockSmall.jpg");
	sprite->setAnchorPoint(Vec2(0.0, 0.0));
	sprite2->setAnchorPoint(Vec2(0.0, 0.0));

	sprite->addChild(sprite2);

	sprite->setPosition(100, 100);
	sprite2->setPosition(0, 0);

	this->addChild(sprite, 0);

	return true;
} 

void GraphicsScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

}