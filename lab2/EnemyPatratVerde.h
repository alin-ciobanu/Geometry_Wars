/*
	author: Ciobanu Alin Emanuel, 332CC
*/

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

class EnemyPatratVerde: public Enemy
{
public:
	Color color;
	Rectangle2D *patratContur;
	Rectangle2D *patratInside;
	Rectangle2D *patratContur1;
	Rectangle2D *patratInside1;
	float laturaContur;
	float stangaJosX, stangaJosY;
	float unghi;
	float laturaInside;
public:
	EnemyPatratVerde(int, int);
	void addEnemy2D(Visual2D*);
	void removeEnemy2D(Visual2D*);
	void move(int, Player*);
	~EnemyPatratVerde(void);
};
