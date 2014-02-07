#include "Enemy.h"
#include "Enemy2Patrate.h"
#include "Enemy4Triunghiuri.h"
#include "EnemyPatratFace.h"
#include "EnemyPatratVerde.h"
#include <vector>
#pragma once

#define LEVEL_MAX 11


class Level
{
public:
	vector<Enemy*> enemies;
	vector<int> viteze;
	int levelMax;
public:
	Level(void);
	void newLevel(int levelNo);
	~Level(void);
};

