#include "Enemy2Patrate.h"
#include <cstdlib>
#include <time.h> 


Enemy2Patrate::Enemy2Patrate(int coltStangaSusX, int coltStangaSusY)
{

	score = 10;
	color = Color(1, 0, 1); // mov

	latura = 30;
	laturaMare = latura + latura / 2;

	patratSus = new Rectangle2D(Point2D(coltStangaSusX, coltStangaSusY - latura), 
		latura, latura, color, false);
	patratJos = new Rectangle2D(Point2D(coltStangaSusX + latura / 2, coltStangaSusY - laturaMare), 
		latura, latura, color, false);
	patratSus1 = new Rectangle2D(Point2D(coltStangaSusX + 1, coltStangaSusY - latura + 1), 
		latura - 2, latura - 2, color, false);
	patratJos1 = new Rectangle2D(Point2D(coltStangaSusX + latura / 2 + 1, 
		coltStangaSusY - laturaMare + 1), latura - 2, latura - 2, color, false);

	pasX = 0;
	pasY = 0;

	srand(time(NULL));
	unghi = ((float) (rand() % 360)) * PI / 180;

	stangaSusX = (float) coltStangaSusX;
	stangaSusY = (float) coltStangaSusY;

	cercuri_coliziune.push_back(
		Cerc(coltStangaSusX + latura / 2, coltStangaSusY - latura / 2, sqrt(2) / 2 * latura)
		);
	cercuri_coliziune.push_back(
		Cerc(coltStangaSusX + latura, coltStangaSusY - latura, sqrt(2) / 2 * latura)
		);

}

void Enemy2Patrate::addEnemy2D(Visual2D *v2d)
{
	DrawingWindow::addObject2D_to_Visual2D(patratSus, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratJos, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratSus1, v2d);
	DrawingWindow::addObject2D_to_Visual2D(patratJos1, v2d);

}

void Enemy2Patrate::move (int distance, Player*)
{

	float nextPositionX = stangaSusX + pasX + cos(unghi);
	float nextPositionY = stangaSusY + pasY + sin(unghi);

	while (distance--) 	
	{

		if (origXPlayfield >= nextPositionX || 
			origXPlayfield + widthPlayfield <= nextPositionX + laturaMare || 
			origYPlayfield >= nextPositionY - laturaMare || 
			origYPlayfield + heightPlayfield <= nextPositionY
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
		nextPositionX = stangaSusX + pasX + cos(unghi);
		nextPositionY = stangaSusY + pasY + sin(unghi);

		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(patratSus);
		Transform2D::applyTransform(patratJos);
		Transform2D::applyTransform(patratSus1);
		Transform2D::applyTransform(patratJos1);

	}

}

void Enemy2Patrate::removeEnemy2D(Visual2D* v2d)
{

	DrawingWindow::removeObject2D_from_Visual2D(patratSus, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratJos, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratSus1, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(patratJos1, v2d);

}

Enemy2Patrate::~Enemy2Patrate(void)
{
}
