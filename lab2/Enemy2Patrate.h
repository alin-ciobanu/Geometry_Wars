#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Color.h"
#include "Enemy.h"
#pragma once

class Enemy2Patrate: public Enemy
{
public:
	float unghi;
	float latura;
	float laturaMare;
	Rectangle2D *patratSus;
	Rectangle2D *patratJos;
	Rectangle2D *patratSus1;
	Rectangle2D *patratJos1;
	Color color;
	float stangaSusX, stangaSusY;
public:
	Enemy2Patrate(int, int);
	void addEnemy2D(Visual2D*);
	void move(int, Player*);
	void removeEnemy2D(Visual2D*);
	~Enemy2Patrate(void);
};

