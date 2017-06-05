#include "AudioScene.h"
#include "SimpleAudioEngine.h"


cocos2d::Scene* AudioScene::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = AudioScene::create();
	scene->addChild(layer);
	return scene;
}

bool AudioScene::init()
{
	if (!Layer::init())
		return false;

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

	audio->playBackgroundMusic("cartePostale.mp3");

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [audio](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)->void  {

		switch (keyCode) {
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
			if (audio->isBackgroundMusicPlaying())
				audio->pauseBackgroundMusic();
			else
				audio->resumeBackgroundMusic();
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			audio->playBackgroundMusic("cartePostale.mp3");
			break;

		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			audio->playBackgroundMusic("cartePostale.mp3");
			break;
		}
	};

	this->_eventDispatcher->addEventListenerWithFixedPriority(listener, 2);

	return true;
}