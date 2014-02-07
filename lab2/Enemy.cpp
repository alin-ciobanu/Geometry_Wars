#include "Enemy.h"


Enemy::Enemy(void)
{
}

void Enemy::addEnemy2D(Visual2D*)
{
}

void Enemy::updatePlayfieldSize (float coltStJosX, float coltStJosY, float coltDrSusX, float coltDrSusY, Visual2D *v2d) 
{
	origXPlayfield = coltStJosX;
	origYPlayfield = coltStJosY;
	widthPlayfield = coltDrSusX - coltStJosX;
	heightPlayfield = coltDrSusY - coltStJosY;
	playfield = v2d;
}

vector<Cerc> Enemy::getCercuriColiziune () 
{
	return cercuri_coliziune;
}

void Enemy::removeEnemy2D (Visual2D*)
{
}

void Enemy::move(int, Player*)
{
}

Enemy::~Enemy(void)
{
}
