#pragma once

#include "cocos2d.h"
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
    void loadMovementArrows();
    void loadMovementArrowLeftUnSelected(){leftArrow->setTexture("res/leftArrow.png");}
    void loadMovementArrowLeftSelected(){leftArrow->setTexture("res/leftArrowPressed.png");}
    void loadMovementArrowRightUnSelected(){rightArrow->setTexture("res/rightArrow.png");}
    void loadMovementArrowRightSelected(){rightArrow->setTexture("res/rightArrowPressed.png");}
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
    
    void moveHero();
    void moveHeroLeft();
    void moveHeroRight();
    
    bool isLeftArrowPressed();
    bool isRightArrowPressed();
    
    void touchBegan(const vector<cocos2d::Touch*> touch, cocos2d::Event* event);
    void touchMoved(const vector<cocos2d::Touch*> touch, cocos2d::Event* event);
    void touchEnded(const vector<cocos2d::Touch*> touch, cocos2d::Event* event);

	cocos2d::Sprite* backGround;
	cocos2d::Sprite* earth;
	cocos2d::Sprite* heroSpaceShip;
	cocos2d::Sprite* level;
    cocos2d::Sprite* leftArrow;
    cocos2d::Sprite* rightArrow;

	vector < cocos2d::Sprite* > heroBullets;
	vector < cocos2d::Sprite* > enemies;
	vector < cocos2d::Sprite* > enemyBullets;
	vector < cocos2d::Sprite* > heroLifes;
    
    cocos2d::EventListenerTouchAllAtOnce* touchListener;
    cocos2d::Touch* leftArrowTouch;
    cocos2d::Touch* rightArrowTouch;
	
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
    bool leftArrowPressed;
    bool rightArrowPressed;

	bool isPaused;
};
