#include "MouseScene.h"

USING_NS_CC;

cocos2d::Scene* MouseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MouseScene::create();
	scene->addChild(layer);

	return scene;
}

bool MouseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerMouse::create();
	listener->onMouseDown = [](cocos2d::Event* event) {

		EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);

		int x = mouseEvent->getLocation().x;
		int y = mouseEvent->getLocation().y;
		char tempx[4];
		char tempy[4];


		cocos2d::log("Mouse button pressed ");


	};

	listener->onMouseMove = [](cocos2d::Event* event) {
		// Cast Event to EventMouse for position details like above
		cocos2d::log("Mouse moved event");
	};

	listener->onMouseScroll = [](cocos2d::Event* event) {
		cocos2d::log("Mouse wheel scrolled");
	};

	listener->onMouseUp = [](cocos2d::Event* event) {
		cocos2d::log("Mouse button released");
	};

	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

	return true;
}
