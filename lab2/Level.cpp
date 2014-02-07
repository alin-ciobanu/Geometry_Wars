#include "Level.h"


Level::Level(void)
{

	levelMax = LEVEL_MAX;

}

void Level::newLevel(int levelNo)
{

	enemies.clear();
	viteze.clear();

	switch (levelNo)
	{
		
	case 1:
		{
			enemies.push_back(new EnemyPatratVerde (100, 100));
			viteze.push_back(1);
			break;
		}
	case 2:
		{
			enemies.push_back(new EnemyPatratVerde (200, 100));
			viteze.push_back(1);
			enemies.push_back(new Enemy2Patrate (250, 100));
			viteze.push_back(1);
			break;
		}
	case 3:
		{
			enemies.push_back(new Enemy2Patrate(100, 100));
			viteze.push_back(1);
			enemies.push_back(new EnemyPatratVerde(200, 100));
			viteze.push_back(1);
			enemies.push_back(new Enemy2Patrate (500, 500));
			viteze.push_back(1);
			break;
		}
	case 4:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratVerde(500, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy2Patrate(300, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratVerde(100, 500));
			viteze.push_back(2);
			break;
		}
	case 5:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(1);
			break;
		}
	case 6:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(2);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(3);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(2);
			break;
		}
	case 7:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(3);
			enemies.push_back(new Enemy2Patrate(100, 200));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(150, 150));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(1);
			break;
		}
	case 8:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(3);
			enemies.push_back(new Enemy2Patrate(150, 150));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(150, 200));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(2);
			break;
		}
	case 9:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(3);
			enemies.push_back(new Enemy2Patrate(150, 150));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratVerde(250, 150));
			viteze.push_back(3);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(4);
			enemies.push_back(new EnemyPatratFace (400, 550));
			viteze.push_back(4);
			enemies.push_back(new Enemy4Triunghiuri(300, 500));
			viteze.push_back(2);
			enemies.push_back(new Enemy4Triunghiuri(250, 500));
			viteze.push_back(2);
			break;
		}
	case 10:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(5);
			enemies.push_back(new Enemy2Patrate(100, 200));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratVerde(100, 150));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(4);
			enemies.push_back(new EnemyPatratFace (500, 400));
			viteze.push_back(4);
			enemies.push_back(new Enemy4Triunghiuri(400, 500));
			viteze.push_back(3);
			enemies.push_back(new Enemy4Triunghiuri(100, 400));
			viteze.push_back(3);
			break;
		}
	case 11:
		{
			enemies.push_back(new Enemy2Patrate(200, 200));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratVerde(300, 200));
			viteze.push_back(5);
			enemies.push_back(new Enemy2Patrate(150, 250));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratVerde(250, 150));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratFace (500, 500));
			viteze.push_back(5);
			enemies.push_back(new EnemyPatratFace (450, 550));
			viteze.push_back(5);
			enemies.push_back(new Enemy4Triunghiuri(250, 450));
			viteze.push_back(5);
			enemies.push_back(new Enemy4Triunghiuri(350, 500));
			viteze.push_back(5);
			break;
		}
	}

}

Level::~Level(void)
{
}
