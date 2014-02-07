/*
	author: Ciobanu Alin Emanuel, 332CC
*/

#include "EnemyPatratVerde.h"
#include <cstdlib>
#include <time.h> 


EnemyPatratVerde::EnemyPatratVerde(int coltStangaJosX, int coltStangaJosY)
{

	score = 10;

	color = Color(0, 1, 0); // verde
	laturaContur = 30;
	laturaInside = sqrt (2 * (laturaContur / 2) * (laturaContur / 2));

	patratContur = new Rectangle2D(Point2D(coltStangaJosX, coltStangaJosY), 
		laturaContur, laturaContur, color, false);
	patratInside = new Rectangle2D(Point2D(coltStangaJosX, coltStangaJosY), 
		laturaInside, laturaInside, color, false);
	patratContur1 = new Rectangle2D(Point2D(coltStangaJosX + 1, coltStangaJosY + 1), 
		laturaContur - 2, laturaContur - 2, color, false);
	patratInside1 = new Rectangle2D(Point2D(coltStangaJosX + 1, coltStangaJosY + 1), 
		laturaInside - 2, laturaInside - 2, color, false);

	pasX = 0;
	pasY = 0;

	srand(time(NULL));
	unghi = ((float) (rand() % 360)) * PI / 180; 

	stangaJosX = (float) coltStangaJosX;
	stangaJosY = (float) coltStangaJosY;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(-coltStangaJosX, -coltStangaJosY);
	Transform2D::rotateMatrix(PI/4);
	Transform2D::translateMatrix(coltStangaJosX + laturaContur / 2, coltStangaJosY);
	Transform2D::applyTransform(patratInside);
	Transform2D::applyTransform(patratInside1);

	cercuri_coliziune.push_back(
		Cerc(coltStangaJosX + laturaContur / 2, 
		coltStangaJosY + laturaContur / 2, sqrt(2) / 2 * laturaContur));

}

void EnemyPatratVerde::addEnemy2D(Visual2D *v2d)
{
	DrawingWindow::addObject2D_to_Visual2D(patratContur, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratInside, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratContur1, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratInside1, v2d);

}

void EnemyPatratVerde::move (int distance, Player*)
{

	float nextPositionX = stangaJosX + pasX + cos(unghi);
	float nextPositionY = stangaJosY + pasY + sin(unghi);

	while (distance--) 	
	{

		if (origXPlayfield >= nextPositionX || 
			origXPlayfield + widthPlayfield <= nextPositionX + laturaContur || 
			origYPlayfield >= nextPositionY || // de completat
			origYPlayfield + heightPlayfield <= nextPositionY + laturaContur // de completat
			) 
		{
			srand(time(NULL));
			unghi += ((float) ((rand() % 90) + 90)) * PI / 180;
			if (unghi > 2 * PI)
				unghi -= 2 * PI;
		}

		Transform2D::loadIdentityMatrix();

		pasX += cos (unghi);
		pasY += sin (unghi);
		nextPositionX = stangaJosX + pasX + cos(unghi);
		nextPositionY = stangaJosY + pasY + sin(unghi);

		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(patratContur);
		Transform2D::applyTransform(patratContur1);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-stangaJosX, -stangaJosY);
		Transform2D::rotateMatrix(PI/4);
		Transform2D::translateMatrix(stangaJosX + laturaContur / 2, stangaJosY);
		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(patratInside);
		Transform2D::applyTransform(patratInside1);

	}

}

void EnemyPatratVerde::removeEnemy2D(Visual2D* v2d)
{

	DrawingWindow::removeObject2D_from_Visual2D(patratContur, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratInside, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratContur1, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratInside1, v2d);

}

EnemyPatratVerde::~EnemyPatratVerde(void)
{
}
