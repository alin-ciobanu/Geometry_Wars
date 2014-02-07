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
#include "Player.h"
#include "Enemy.h"
#include <vector>
#pragma once

#define LATURA 30
#define INIT_UNGHI 0
#define RAZA 3

class EnemyPatratFace: public Enemy
{
public:
	Rectangle2D *patratMare;
	Rectangle2D *ochiStg, *ochiDr;
	Rectangle2D *gura;
	Circle2D *cercStgSus, *cercDrSus, *cercStgJos, *cercDrJos;
	float latura;
	float radius_cerc;
	Color color;
	float stgJosX, stgJosY;
	float unghi;
public:
	EnemyPatratFace(int, int);
	void addEnemy2D(Visual2D*);
	void move(int, Player*); 
	void removeEnemy2D(Visual2D*);
	~EnemyPatratFace(void);
};

