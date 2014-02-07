/*
	author: Ciobanu Alin Emanuel, 332CC
*/

#include "EnemyPatratFace.h"


EnemyPatratFace::EnemyPatratFace(int x, int y)
{

	score = 25;
	pasX = pasY = 0;
	unghi = INIT_UNGHI;

	color = Color(1, 247.0f/255.0f, 0);
	stgJosX = (float) x;
	stgJosY = (float) y;

	latura = LATURA;
	radius_cerc = RAZA;

	patratMare = new Rectangle2D(Point2D(stgJosX, stgJosY), latura, latura, color, false);
	ochiStg = new Rectangle2D(Point2D(stgJosX + latura / 5, stgJosY + 3 * latura / 5), 
		latura / 5, latura / 5, color, false);
	ochiDr = new Rectangle2D(Point2D(stgJosX + 0.6 * latura, stgJosY + 3 * latura / 5), 
		latura / 5, latura / 5, color, false);
	gura = new Rectangle2D(Point2D(stgJosX + 0.3 * latura, stgJosY + latura / 5),
		0.4 * latura, latura / 5, color, false);
	cercStgJos = new Circle2D(Point2D(stgJosX - radius_cerc, 
		stgJosY - radius_cerc), radius_cerc, color, false);
	cercStgSus = new Circle2D(Point2D(stgJosX - radius_cerc, 
		stgJosY + latura + radius_cerc), radius_cerc, color, false);
	cercDrJos = new Circle2D(Point2D(stgJosX + latura + radius_cerc, 
		stgJosY - radius_cerc), radius_cerc, color, false);
	cercDrSus = new Circle2D(Point2D(stgJosX + latura + radius_cerc, 
		stgJosY + latura + radius_cerc), radius_cerc, color, false);
	
	cercuri_coliziune.push_back(Cerc(stgJosX + latura / 2, stgJosY + latura / 2, (sqrt(2) / 2) * latura));

}

void EnemyPatratFace::addEnemy2D(Visual2D* playfield)
{

	DrawingWindow::addObject2D_to_Visual2D(patratMare, playfield);
	DrawingWindow::addObject2D_to_Visual2D(ochiDr, playfield);
	DrawingWindow::addObject2D_to_Visual2D(ochiStg, playfield);
	DrawingWindow::addObject2D_to_Visual2D(gura, playfield);
	DrawingWindow::addObject2D_to_Visual2D(cercDrJos, playfield);
	DrawingWindow::addObject2D_to_Visual2D(cercDrSus, playfield);
	DrawingWindow::addObject2D_to_Visual2D(cercStgJos, playfield);
	DrawingWindow::addObject2D_to_Visual2D(cercStgSus, playfield);

}

void EnemyPatratFace::move(int distance, Player* player) 
{

	while (distance--) 	
	{

		float player_x, player_y;
		player_x = player->origX + player->pasX;
		player_y = player->origY + player->pasY;

		float this_x = this->stgJosX + this->pasX;
		float this_y = this->stgJosY + this->pasY;

		float nextPositionX = stgJosX + pasX + cos(unghi);
		float nextPositionY = stgJosY + pasY + sin(unghi);

		if (origXPlayfield >= nextPositionX  - 2 * radius_cerc || 
			origXPlayfield + widthPlayfield <= nextPositionX + latura + 2 * radius_cerc || 
			origYPlayfield >= nextPositionY - 2 * radius_cerc ||
			origYPlayfield + heightPlayfield <= nextPositionY + latura + 2 * radius_cerc
			)
		{
			float d = sqrt (pow ((player_x - this_x), 2) +  pow ((player_y - this_y), 2));
			unghi = acos(((player_x - this_x)) / d);
			if (this_y >= player_y)
				unghi *= (-1);
		}


		Transform2D::loadIdentityMatrix();

		pasX += cos (unghi);
		pasY += sin (unghi);
		nextPositionX = stgJosX + pasX + cos(unghi);
		nextPositionY = stgJosY + pasY + sin(unghi);

		Transform2D::loadIdentityMatrix();

		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(cercDrJos);
		Transform2D::applyTransform(cercDrSus);
		Transform2D::applyTransform(cercStgJos);
		Transform2D::applyTransform(cercStgSus);
		Transform2D::applyTransform(patratMare);
		Transform2D::applyTransform(ochiDr);
		Transform2D::applyTransform(ochiStg);
		Transform2D::applyTransform(gura);

	}

}

void EnemyPatratFace::removeEnemy2D(Visual2D* playfield)
{

	DrawingWindow::removeObject2D_from_Visual2D(patratMare, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(ochiDr, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(ochiStg, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(gura, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(cercDrJos, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(cercDrSus, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(cercStgJos, playfield);
	DrawingWindow::removeObject2D_from_Visual2D(cercStgSus, playfield);

}

EnemyPatratFace::~EnemyPatratFace(void)
{
}
