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
#include "Player.h"
#pragma once

#define LATURA 20
#define RADIUS 5

class Enemy4Triunghiuri: public Enemy
{
public:
	Circle2D* cercMijloc;
	Polygon2D* triunghi1;
	Polygon2D* triunghi2;
	Polygon2D* triunghi3;
	Polygon2D* triunghi4;
	Polygon2D* triunghi11;
	Polygon2D* triunghi21;
	Polygon2D* triunghi31;
	Polygon2D* triunghi41;
	float origX, origY;
	float radius;
	float latura;
	Color colorCerc;
	Color colorTri;
	float unghi;
public:
	Enemy4Triunghiuri(int, int);
	void addEnemy2D(Visual2D*);
	void move(int, Player*);
	void removeEnemy2D(Visual2D*);
	~Enemy4Triunghiuri(void);
};

