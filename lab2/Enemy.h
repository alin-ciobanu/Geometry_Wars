#pragma once
#include "Cerc.h"
#include "Framework/Visual2D.h"
#include <vector>

class Player;

#define PI 3.14159265358979323846

class Enemy
{
public:
	vector<Cerc> cercuri_coliziune;
	float pasX, pasY;
	int score;
protected:
	float origXPlayfield, origYPlayfield, widthPlayfield, heightPlayfield; 
	Visual2D *playfield;
public:
	virtual void addEnemy2D(Visual2D*);
	vector<Cerc> getCercuriColiziune();
	virtual void removeEnemy2D(Visual2D*);
	void updatePlayfieldSize(float, float, float, float, Visual2D*);
	virtual void move(int, Player*);
	Enemy(void);
	~Enemy(void);
};

