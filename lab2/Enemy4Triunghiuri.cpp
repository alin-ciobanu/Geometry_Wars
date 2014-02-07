/*
	author: Ciobanu Alin Emanuel, 332CC
*/

#include "Enemy4Triunghiuri.h"

Enemy4Triunghiuri::Enemy4Triunghiuri(int x, int y)
{

	score = 50;

	colorCerc = Color(120.0f/255.0f, 199.0f/255.0f, 236.0f/255.0f);
	colorTri = Color(120.0f/255.0f, 236.0f/255.0f, 141.0f/255.0f);

	origX = (float) x;
	origY = (float) y;

	latura = LATURA;
	radius = RADIUS;

	cercMijloc = new Circle2D(Point2D(origX, origY), radius, colorCerc, true);
	cercuri_coliziune.push_back(Cerc(origX, origY, radius));

	triunghi1 = new Polygon2D(colorTri, false);
	triunghi2 = new Polygon2D(colorTri, false);
	triunghi3 = new Polygon2D(colorTri, false);
	triunghi4 = new Polygon2D(colorTri, false);
	triunghi11 = new Polygon2D(colorTri, false);
	triunghi21 = new Polygon2D(colorTri, false);
	triunghi31 = new Polygon2D(colorTri, false);
	triunghi41 = new Polygon2D(colorTri, false);

	float h = (sqrt(3)/2) * latura; // inaltimea

	triunghi1->addPoint(Point2D(origX, origY + radius));
	triunghi1->addPoint(Point2D(origX, origY + radius + latura));
	triunghi1->addPoint(Point2D(origX + h, origY + radius + latura / 2));
	cercuri_coliziune.push_back(Cerc(origX + h / 3, origY + radius + latura / 2, h / 2));

	triunghi2->addPoint(Point2D(origX + radius, origY));
	triunghi2->addPoint(Point2D(origX + radius + latura, origY));
	triunghi2->addPoint(Point2D(origX + radius + latura / 2, origY - h));
	cercuri_coliziune.push_back(Cerc(origX + radius + latura / 2, origY - h / 3, h / 2));

	triunghi3->addPoint(Point2D(origX, origY - radius));
	triunghi3->addPoint(Point2D(origX, origY - radius - latura));
	triunghi3->addPoint(Point2D(origX - h, origY - radius - latura / 2));
	cercuri_coliziune.push_back(Cerc(origX - h / 3, origY - radius - latura / 2, h / 2));

	triunghi4->addPoint(Point2D(origX - radius, origY));
	triunghi4->addPoint(Point2D(origX - radius - latura, origY));
	triunghi4->addPoint(Point2D(origX - radius - latura / 2, origY + h));
	cercuri_coliziune.push_back(Cerc(origX - radius - latura / 2, origY + h / 3, h / 2));

	triunghi11->addPoint(Point2D(origX + 1, origY + radius));
	triunghi11->addPoint(Point2D(origX + 1, origY + radius + latura));
	triunghi11->addPoint(Point2D(origX + h - 1, origY + radius + latura / 2));

	triunghi21->addPoint(Point2D(origX + radius, origY - 1));
	triunghi21->addPoint(Point2D(origX + radius + latura, origY - 1));
	triunghi21->addPoint(Point2D(origX + radius + latura / 2, origY - h + 1));

	triunghi31->addPoint(Point2D(origX - 1, origY - radius));
	triunghi31->addPoint(Point2D(origX - 1, origY - radius - latura));
	triunghi31->addPoint(Point2D(origX - h + 1, origY - radius - latura / 2));

	triunghi41->addPoint(Point2D(origX - radius, origY + 1));
	triunghi41->addPoint(Point2D(origX - radius - latura, origY + 1));
	triunghi41->addPoint(Point2D(origX - radius - latura / 2, origY + h - 1));

	pasX = 0;
	pasY = 0;

}

void Enemy4Triunghiuri::addEnemy2D(Visual2D* v2d)
{

	DrawingWindow::addObject2D_to_Visual2D(cercMijloc, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi1, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi2, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi3, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi4, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi11, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi21, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi31, v2d);
	DrawingWindow::addObject2D_to_Visual2D(triunghi41, v2d);

}

void Enemy4Triunghiuri::move(int distance, Player* player)
{

	while (distance--) 	
	{

		float player_x, player_y;
		player_x = player->origX + player->pasX;
		player_y = player->origY + player->pasY;

		float this_x = this->origX + this->pasX;
		float this_y = this->origY + this->pasY;

		float d = sqrt (pow ((player_x - this_x), 2) +  pow ((player_y - this_y), 2));
		unghi = acos(((player_x - this_x)) / d);
		if (this_y >= player_y)
			unghi *= (-1);

		float nextPositionX = origX + pasX + cos(unghi);
		float nextPositionY = origY + pasY + sin(unghi);

		if (unghi > 2 * PI)
			unghi -= 2 * PI;
		if (unghi < 0)
			unghi += 2 * PI;

		Transform2D::loadIdentityMatrix();

		pasX += cos (unghi);
		pasY += sin (unghi);
		nextPositionX = origX + pasX + cos(unghi);
		nextPositionY = origY + pasY + sin(unghi);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-origX, -origY);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(origX, origY);

		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(cercMijloc);
		Transform2D::applyTransform(triunghi1);
		Transform2D::applyTransform(triunghi2);
		Transform2D::applyTransform(triunghi3);
		Transform2D::applyTransform(triunghi4);
		Transform2D::applyTransform(triunghi11);
		Transform2D::applyTransform(triunghi21);
		Transform2D::applyTransform(triunghi31);
		Transform2D::applyTransform(triunghi41);

	}

}

void Enemy4Triunghiuri::removeEnemy2D(Visual2D* v2d)
{

	DrawingWindow::removeObject2D_from_Visual2D(cercMijloc, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi1, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi2, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi3, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi4, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi11, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi21, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi31, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(triunghi41, v2d);

}

Enemy4Triunghiuri::~Enemy4Triunghiuri(void)
{
}
