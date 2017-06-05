#include "Level1Scene.h"

USING_NS_CC;

cocos2d::Scene * Level1Scene::createScene()
{
	return Level1Scene::create();
}

bool Level1Scene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// level settings
	timeLastShot = 0;
	timeLastShotLimit = 0.5;
	enemiesMovement = true;
	heroNrLifes = 3;

	distanceTravelEnemies = 200;
	speedHeroSpaceShip = 5;
	speedEnemies = 4;
	speedHeroBullet = 1.5;
	speedEnemyBullet = 5;
	nrFlashes = 0;
	timeFlash = 0.2;
	finishTime = 0;
	startTime = 1;

	win = false;
	lose = false;
	started = false;

	this->loadBackGround();
	this->loadPlanetEarth();
	this->loadHeroSpaceShip();
	this->loadEnemies();
	this->loadHeroLifes();

	isPaused = false;

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Level1Scene::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Level1Scene::keyReleased, this);
	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this); 
	
	this->scheduleUpdate();
	
	return true;
}

void Level1Scene::loadBackGround()
{
	backGround = cocos2d::Sprite::create("background.png");

	double scaleX = double(Director::getInstance()->getVisibleSize().width) / double(backGround->getBoundingBox().size.width);
	double scaleY = double(Director::getInstance()->getVisibleSize().height) / double(backGround->getBoundingBox().size.height);

	double scaleMax = (scaleX > scaleY) ? scaleX : scaleY;

	backGround->setAnchorPoint(Vec2(0.5, 0.5));
	backGround->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	backGround->setScale(scaleMax);

	cocos2d::log("Intro background loaded at scale %f", scaleMax);

	this->addChild(backGround, 0);
}

void Level1Scene::loadPlanetEarth()
{
	// loading earth
	earth = cocos2d::Sprite::create("earth.png");

	double scaleX = double(Director::getInstance()->getVisibleSize().width) / double(earth->getBoundingBox().size.width);
	double scaleY = double(Director::getInstance()->getVisibleSize().height) / double(earth->getBoundingBox().size.height);

	double scaleMax = (scaleX > scaleY) ? scaleX / 1.5 : scaleY / 1.5;

	// bigger earth in first level
	earth->setAnchorPoint(Vec2(0.65, 0.35));
	earth->setPosition(this->getBoundingBox().getMaxX(), this->getBoundingBox().getMinY());
	earth->setScale(scaleMax);

	cocos2d::log("Intro planet earth loaded at scale %f", scaleMax);

	this->addChild(earth);
}


void Level1Scene::loadHeroSpaceShip()
{
	heroSpaceShip = cocos2d::Sprite::create("elonBack.png");
	heroSpaceShip->setAnchorPoint(Vec2(0.5, 0.5));
	heroSpaceShip->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().size.height / 7);
	heroSpaceShip->setScale(0.3);
	this->addChild(heroSpaceShip);
}

void Level1Scene::loadHeroSpaceShipCenter()
{
	heroSpaceShip->setTexture("elonBack.png");
}

void Level1Scene::loadHeroSpaceShipLeft()
{
	heroSpaceShip->setTexture("elonLeft.png");
}

void Level1Scene::loadHeroSPaceShipRight()
{
	heroSpaceShip->setTexture("elonRight.png");
}

void Level1Scene::loadHeroLifes()
{
	for (int i = 1; i <= heroNrLifes; i++)
	{
		auto life = Sprite::create("life.png");
		life->setAnchorPoint(Vec2(0.5, 0.5));
		life->setScale(0.125);
		int x = Director::getInstance()->getVisibleSize().width - (i * life->getBoundingBox().size.width);
		int y = this->getBoundingBox().size.height * 0.895;
		life->setPosition(Vec2(x, y));
		heroLifes.push_back(life);
		this->addChild(life, 3);
	}
}

void Level1Scene::loadHeroBullet()
{
	auto bullet = Sprite::create("laserGreen.png");
	
	bullet->setScale(0.2);
	bullet->setScaleX(0.3);
	bullet->setAnchorPoint(Vec2(0.5, 0.5));
	bullet->setPosition(Vec2(heroSpaceShip->getBoundingBox().getMidX(), 
		heroSpaceShip->getBoundingBox().getMaxY() + bullet->getBoundingBox().size.height/2));
	
	bullet->runAction(MoveTo::create(speedHeroBullet, Vec2(bullet->getBoundingBox().getMidX(),
		this->getBoundingBox().size.height + bullet->getBoundingBox().size.height + 1)));
	
	this->addChild(bullet);

	heroBullets.push_back(bullet);
}

void Level1Scene::loadEnemyBullet()
{
	int enemyIndex = rand() % enemies.size();

	auto bullet = Sprite::create("laserRed.png");

	bullet->setScale(0.2);
	bullet->setScaleX(0.3);
	bullet->setAnchorPoint(Vec2(0.5, 0.5));
	bullet->setPosition(Vec2(enemies[enemyIndex]->getBoundingBox().getMidX(),
		enemies[enemyIndex]->getBoundingBox().getMidY() + 5 - bullet->getBoundingBox().size.height / 2));

	bullet->runAction(MoveTo::create(speedEnemyBullet, Vec2(bullet->getBoundingBox().getMidX(),
		-(this->getBoundingBox().size.height + bullet->getBoundingBox().size.height + 1))));

	this->addChild(bullet, 1);

	enemyBullets.push_back(bullet);
}

void Level1Scene::loadEnemy(int posX, int posY)
{
	auto enemy = Sprite::create("redShip.png");

	enemy->setScale(0.2);
	enemy->setAnchorPoint(Vec2(0.5, 0.5));
	enemy->setPosition(Vec2(posX, posY));

	enemies.push_back(enemy);
	this->addChild(enemy, 2);
}

void Level1Scene::loadEnemies()
{
	srand(time(NULL));
	
	for (int poy = this->getBoundingBox().size.height * 0.85, i = 1; i <= 2; i++, poy-=90)
	{
		for (int pox = this->getBoundingBox().size.width * 0.1, j = 1; j <= 7; j++, pox+=90)
		{
			loadEnemy(pox, poy);
		}
	}

}

// move all enemies left
void Level1Scene::moveEnemiesLeft()
{
	// move enemies one by one
	for (auto enemy : enemies)
	{
		enemy->runAction(MoveBy::create(speedEnemies, Vec2(-this->getBoundingBox().size.width * 0.2, 0)));
	}
}

// move all enemies right
void Level1Scene::moveEnemiesRight()
{
	// move enemies one by one
	for (auto enemy : enemies)
	{
		enemy->runAction(MoveBy::create(speedEnemies, Vec2(+this->getBoundingBox().size.width * 0.2, 0)));
	}
}

void Level1Scene::removeEnemiesCollsion()
{
	// remove bullets and enemies at collision
	for (int i = 0; i < heroBullets.size(); i++)
	{
		// if the bullet collides with an enemy
		for (int j = 0; j < enemies.size(); j++)
		{
			if (enemies[j]->getBoundingBox().containsPoint(Vec2(
				heroBullets[i]->getBoundingBox().getMaxX() + 10,
				heroBullets[i]->getBoundingBox().getMaxY())) ||
				enemies[j]->getBoundingBox().containsPoint(Vec2(
					heroBullets[i]->getBoundingBox().getMinX() - 10,
					heroBullets[i]->getBoundingBox().getMaxY())))
			{
				// remove bullet
				this->removeChild(heroBullets[i]);
				heroBullets.erase(heroBullets.begin() + i);

				// remove enemy
				this->removeChild(enemies[j]);
				enemies.erase(enemies.begin() + j);

				break;
			}
		}
	}
}

void Level1Scene::removeHeroLifeCollsion()
{
	// remove bullets and hero lifes at collision
	for (int i = 0; i < enemyBullets.size(); i++)
	{
		// if the bullet collides with hero
		if (heroSpaceShip->getBoundingBox().containsPoint(Vec2(
				enemyBullets[i]->getBoundingBox().getMaxX() + 5,
				enemyBullets[i]->getBoundingBox().getMinY())) ||
			heroSpaceShip->getBoundingBox().containsPoint(Vec2(
				enemyBullets[i]->getBoundingBox().getMinX() - 5,
				enemyBullets[i]->getBoundingBox().getMinY())))
		{
			// remove bullet
			this->removeChild(enemyBullets[i]);
			enemyBullets.erase(enemyBullets.begin() + i);

			// destroy one life and animation for hero spaceship
			if (heroNrLifes)
			{
				this->removeChild(heroLifes[heroLifes.size() - 1]);
				heroLifes.pop_back();
				heroNrLifes--;
			}
			if (heroNrLifes == 0)
			{
				// run explosion
				this->removeChild(heroSpaceShip);
				finishTime = 2;
				lose = true;
			}
			else
			{
				nrFlashes = 4;
				flash = true;
			}
			break;
		}
	}
}

void Level1Scene::heroSpaceShipFlashing()
{
	if (flash)
	{
		heroSpaceShip->setOpacity(25);
		timeFlash = 0.15;
		flash = false;
	}
	else
	{
		heroSpaceShip->setOpacity(105 + heroNrLifes * 50);
		timeFlash = 0.15;
		nrFlashes--;
		flash = true;
	}
}

// winning moment
void Level1Scene::winningMoment()
{
	auto win = Sprite::create("youWin.png");

	win->setScale(0.4);
	win->setAnchorPoint(Vec2(0.5, 0.5));
	win->setPosition(Vec2(this->getBoundingBox().size.width / 2, this->getBoundingBox().size.height / 2));

	auto scaleBy = ScaleBy::create(2, 1.1);
	win->runAction(scaleBy);

	this->addChild(win);
}

// losing moment
void Level1Scene::losingMoment()
{
	auto lose = Sprite::create("youLose.png");

	lose->setScale(0.4);
	lose->setAnchorPoint(Vec2(0.5, 0.5));
	lose->setPosition(Vec2(this->getBoundingBox().size.width/2, this->getBoundingBox().size.height/2));

	auto scaleBy = ScaleBy::create(2, 1.1);
	lose->runAction(scaleBy);

	this->addChild(lose);
}

void Level1Scene::showLevel()
{
	level = cocos2d::Sprite::create("lvl1.png");

	level->setAnchorPoint(Vec2(0.5, 0.5));
	level->setScale(0.3);
	level->setPosition(Vec2(this->getBoundingBox().size.width / 2, this->getBoundingBox().size.height / 2));

	this->addChild(level,2);
}

bool Level1Scene::isEnemiesMoving()
{
	if (enemies[0]->getNumberOfRunningActions())
		return true;
	return false;
}

void Level1Scene::startMainMenuScene()
{
	auto intro = Intro::createScene();
	Director::getInstance()->replaceScene(intro);
}

void Level1Scene::startNextLevel()
{
	auto nextLevel = Level2Scene::create();
	Director::getInstance()->replaceScene(nextLevel);
}

void Level1Scene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keysDuration.find(keyCode) == keysDuration.end()) 
		keysDuration[keyCode] = std::chrono::high_resolution_clock::now();

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if(finishTime == 0)
			loadHeroBullet();
	}
}

void Level1Scene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if(finishTime == 0)
			loadHeroSpaceShipCenter();
	}

	keysDuration.erase(keyCode);
}

double Level1Scene::keyPressedDuration(cocos2d::EventKeyboard::KeyCode code) 
{
	if (!isKeyPressed(code))
		return 0;  

	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - keysDuration[code]).count();
}

bool Level1Scene::isKeyPressed(cocos2d::EventKeyboard::KeyCode code) 
{
	if (keysDuration.find(code) != keysDuration.end())
		return true;
	return false;
}

void Level1Scene::update(float delta)
{
	if (finishTime == 0)
	{
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_ESCAPE))
		{
			startMainMenuScene();
		}
        
		if (isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
		{
			if (this->getBoundingBox().containsPoint(
				Vec2(heroSpaceShip->getBoundingBox().getMinX() - speedHeroSpaceShip,
					heroSpaceShip->getBoundingBox().getMidY())))
			{
				loadHeroSpaceShipLeft();
				heroSpaceShip->runAction(MoveBy::create(delta, Vec2(-speedHeroSpaceShip, 0)));
			}
		}

		if (isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
		{
			if (this->getBoundingBox().containsPoint(
				Vec2(heroSpaceShip->getBoundingBox().getMaxX() + speedHeroSpaceShip,
					heroSpaceShip->getBoundingBox().getMidY())))
			{
				loadHeroSPaceShipRight();
				heroSpaceShip->runAction(MoveBy::create(delta, Vec2(speedHeroSpaceShip, 0)));
			}
		}

		if (startTime >= 0)
		{
			startTime -= delta;
			
			if (started == false)
				showLevel();

			started = true;
		}
		else
		{
			if (started)
				level->runAction(FadeOut::create(1));
			started = false;
		}

		// if there are enemies
		if (enemies.size())
		{
			// if enemies are not moving we make them move left/right
			if (isEnemiesMoving() == false)
			{
				if (enemiesMovement)
				{
					enemiesMovement = false;
					moveEnemiesRight();
				}
				else
				{
					enemiesMovement = true;
					moveEnemiesLeft();
				}
			}
			// here i make the enemies shot
			if (enemies.size() <= 5)
			{
				// if there are less than 5 enemies they will strike harder
				speedEnemies = 2;
				speedEnemyBullet = 3;
				timeLastShotLimit = 0.3;

				if (enemyBullets.size() < 7 && timeLastShot > timeLastShotLimit)
				{
					loadEnemyBullet();
					timeLastShot = 0;
				}
				else
				{
					timeLastShot += delta;
				}
			}
			else
			{
				// if there are more than 5 enemies 
				if (enemyBullets.size() < enemies.size() / 2 && timeLastShot > timeLastShotLimit)
				{
					loadEnemyBullet();
					timeLastShot = 0;
				}
				else
				{
					timeLastShot += delta;
				}
			}
		}
		// go to winning scene after finishTime
		else
		{
			finishTime = 2;
			win = true;
		}

		// remove hero bullets out of visible window
		for (int i = 0; i < heroBullets.size(); i++)
		{
			// if the bullet is not contained in the frame it will be delete
			if (!this->getBoundingBox().containsPoint(Vec2(
				heroBullets[i]->getBoundingBox().getMidX(),
				heroBullets[i]->getBoundingBox().getMinY())))
			{
				// remove bullet
				this->removeChild(heroBullets[i]);
				heroBullets.erase(heroBullets.begin() + i);
			}

		}

		// remove enemy bullets out of visible window
		for (int i = 0; i < enemyBullets.size(); i++)
		{
			// if the bullet is not contained in the frame it will be delete
			if (!this->getBoundingBox().containsPoint(Vec2(
				enemyBullets[i]->getBoundingBox().getMidX(),
				enemyBullets[i]->getBoundingBox().getMaxY())))
			{
				// remove bullet
				this->removeChild(enemyBullets[i]);
				enemyBullets.erase(enemyBullets.begin() + i);
			}

		}

		removeEnemiesCollsion();

		if (nrFlashes)
		{
			if (timeFlash <= 0)
				heroSpaceShipFlashing();
			else
				timeFlash -= delta;
		}
		else
			removeHeroLifeCollsion();
	}
	else
	{
		//if (win)
			//winningMoment();

		if (lose)
			losingMoment();

		// wait before showing the main menu scene
		finishTime -= delta;
		if (finishTime <= 0)
		{
			if (win)
				startNextLevel();

			if(lose)
				startMainMenuScene();
		}
	}
}
