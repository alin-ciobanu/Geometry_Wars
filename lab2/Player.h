#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Color.h"
#include "Enemy.h"
#include "Framework/Color.h"
#pragma once

#define UNGHI 0
#define RAZA 20
#define HEIGHT_BURGHIU 40
#define PI 3.14159265358979323846

class Player
{
public:
	Circle2D *circ;
	Circle2D *circB;
	Circle2D *circC;
	Circle2D *circD;
	Circle2D *circE;
	Circle2D *circF;
	Polygon2D *polygon;
	Polygon2D *polygon2;
	Polygon2D *burghiu;
	Polygon2D *burghiu1;
	float origXPlayfield, origYPlayfield;
	float widthPlayfield, heightPlayfield;
	Color color;
	Color colorBurghiu;
	Visual2D *playfield;
	float origX, origY;
	float pasRotire;
	Point2D pct1;
	Point2D pct2;
	Point2D pct3;
	bool weaponOn;
	Cerc cercBurghiu;
	float pasX, pasY;
	float radius;
	float heightBurghiu;
public:
	Player(float, float);
	void updatePlayfieldSize(float, float, float, float, Visual2D*);
	void addPlayer2D(Visual2D*);
	void removePlayer2D(Visual2D*);
	void rotate(float);
	void move(int);
	void toggleWeapon();
	bool kills(Enemy*);
	bool isKilled(Enemy*);
	~Player(void);
};
