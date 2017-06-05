#pragma once

#include "cocos2d.h"
#include "InputListener.h"
#include "Level2Scene.h"
#include "Intro.h"
#include <map>
#include <vector>
#include <time.h>

using namespace std;

class Level1Scene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(Level1Scene);

	virtual void update(float delta) override;

private:

	void loadBackGround();
	void loadPlanetEarth();
	void loadHeroSpaceShip();
	void loadHeroSpaceShipCenter();
	void loadHeroSpaceShipLeft();
	void loadHeroSPaceShipRight();
	void loadHeroLifes();
	void loadHeroBullet();
	void loadEnemyBullet();
	void loadEnemy(int posX, int posY);
	void loadEnemies();
	void moveEnemiesLeft();
	void moveEnemiesRight();
	void removeEnemiesCollsion();
	void removeHeroLifeCollsion();
	void heroSpaceShipFlashing();
	void winningMoment();
	void losingMoment();
	void showLevel();
	bool isEnemiesMoving();

	// i need to create a pause scene
	// now i use the main menu scene
	void startMainMenuScene();
	void startNextLevel();

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	double keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
	
	cocos2d::EventListenerKeyboard keyboardListener;
	cocos2d::Sprite* backGround;
	cocos2d::Sprite* earth;
	cocos2d::Sprite* heroSpaceShip;
	cocos2d::Sprite* level;

	map<cocos2d::EventKeyboard::KeyCode,
		std::chrono::high_resolution_clock::time_point> keysDuration;

	vector < cocos2d::Sprite* > heroBullets;
	vector < cocos2d::Sprite* > enemies;
	vector < cocos2d::Sprite* > enemyBullets;
	vector < cocos2d::Sprite* > heroLifes;
	
	// units
	double speedHeroSpaceShip;
	double speedEnemies;
	int    distanceTravelEnemies;
	int    heroNrLifes;
	int    nrFlashes;

	// seconds
	double speedHeroBullet;
	double speedEnemyBullet;
	double timeLastShot;
	double timeLastShotLimit;
	double timeFlash;
	double finishTime;
	double startTime;

	// direction True = right
	bool enemiesMovement;
	bool flash;
	bool win;
	bool lose;
	bool started;

	bool isPaused;
};