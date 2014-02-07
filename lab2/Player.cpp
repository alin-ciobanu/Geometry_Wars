#include "Player.h"


Player::Player(float navaOrigineX, float navaOrigineY)
{

	pasRotire = UNGHI;
	weaponOn = false;
	pasX = pasY = 0;

	radius = RAZA;
	heightBurghiu = HEIGHT_BURGHIU;

	color = Color(245.0f/255.0f, 0, 70.0f/255.0f);
	colorBurghiu = Color(255.0f/255.0f, 41.0f/255.0f, 62.0f/255.0f);

	circ = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius, color, false);
	circB = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius-0.5, color, false);
	circC = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius-1, color, false);
	circD = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius-1.5, color, false);
	circE = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius-2, color, false);
	circF = new Circle2D(Point2D(navaOrigineX, navaOrigineY), radius-2.5, color, false);
	polygon = new Polygon2D(color, false);
	polygon2 = new Polygon2D(color, false);
	burghiu = new Polygon2D(colorBurghiu, false);
	burghiu1 = new Polygon2D(colorBurghiu, false);

	polygon->addPoint(Point2D(navaOrigineX, navaOrigineY - 3*radius/5));
	polygon->addPoint(Point2D(navaOrigineX - 3*radius/5, navaOrigineY - radius/2));
	polygon->addPoint(Point2D(navaOrigineX - 2*radius/5, navaOrigineY - radius/2));
	polygon->addPoint(Point2D(navaOrigineX, navaOrigineY));
	polygon->addPoint(Point2D(navaOrigineX - 2*radius/5, navaOrigineY + radius/2));
	polygon->addPoint(Point2D(navaOrigineX - 3*radius/5, navaOrigineY + radius/2));
	polygon->addPoint(Point2D(navaOrigineX, navaOrigineY + 3*radius/5));
	polygon->addPoint(Point2D(navaOrigineX + 3*radius/5, navaOrigineY));

	polygon2->addPoint(Point2D(navaOrigineX + 1, navaOrigineY - 3*radius/5));
	polygon2->addPoint(Point2D(navaOrigineX + 1 - 3*radius/5, navaOrigineY - radius/2));
	polygon2->addPoint(Point2D(navaOrigineX + 1 - 2*radius/5, navaOrigineY - radius/2));
	polygon2->addPoint(Point2D(navaOrigineX + 1, navaOrigineY));
	polygon2->addPoint(Point2D(navaOrigineX + 1 - 2*radius/5, navaOrigineY + radius/2));
	polygon2->addPoint(Point2D(navaOrigineX + 1 - 3*radius/5, navaOrigineY + radius/2));
	polygon2->addPoint(Point2D(navaOrigineX + 1, navaOrigineY + 3*radius/5));
	polygon2->addPoint(Point2D(navaOrigineX + 1 + 3*radius/5, navaOrigineY));

	pct1 = Point2D(navaOrigineX  + radius + 5, navaOrigineY - 3 * radius / 4);
	pct2 = Point2D(navaOrigineX  + radius + 5, navaOrigineY + 3 * radius / 4 );
	pct3 = Point2D(navaOrigineX + radius + 5 + heightBurghiu, navaOrigineY);
	burghiu->addPoint(pct1);
	burghiu->addPoint(pct2);
	burghiu->addPoint(pct3);

	Point2D pct11;
	Point2D pct21;
	Point2D pct31;
	pct11 = Point2D(navaOrigineX  + radius + 5 + 1, navaOrigineY - 3 * radius / 4 + 1);
	pct21 = Point2D(navaOrigineX  + radius + 5 + 1, navaOrigineY + 3 * radius / 4 - 1);
	pct31 = Point2D(navaOrigineX + radius + 5 + heightBurghiu - 1, navaOrigineY);
	burghiu->addPoint(pct11);
	burghiu->addPoint(pct21);
	burghiu->addPoint(pct31);

	origX = navaOrigineX;
	origY = navaOrigineY;

	float radiusBurghiu;
	float laturaA, laturaB, laturaC;
	float arie, s;
	float centru_burghiuX, centru_burghiuY;

	laturaA = sqrt(pow((pct1.x - pct2.x), 2) + pow((pct1.y - pct2.y), 2));
	laturaB = sqrt(pow((pct2.x - pct3.x), 2) + pow((pct2.y - pct3.y), 2));
	laturaC = sqrt(pow((pct1.x - pct3.x), 2) + pow((pct1.y - pct3.y), 2));
	s = (laturaA + laturaB + laturaC) / 2; // semiperimetrul
	arie = sqrt (s * (s - laturaA) * (s - laturaB) * (s - laturaC));
	radiusBurghiu = (laturaA * laturaB *laturaC) / (4 * arie);

	centru_burghiuX = ((pct1.x * pct1.x + pct1.y * pct1.y - pct2.x * pct2.x - pct2.y * pct2.y) / (pct2.y - pct1.y) 
		- (pct2.x * pct2.x + pct2.y * pct2.y - pct3.x * pct3.x - pct3.y * pct3.y) / (- pct2.y + pct3.y))
		/ 
		(((-2) * (pct2.x - pct3.x)) / (-pct2.y + pct3.y) + (2 * (pct1.x - pct2.x)) / (pct2.y - pct1.y));

	centru_burghiuY = ((-2) * centru_burghiuX * (-pct3.x + pct2.x) + pct2.x * pct2.x 
		+ pct2.y * pct2.y - pct3.x * pct3.x - pct3.y * pct3.y) 
		/ 
		((-2) * (-pct2.y + pct3.y));

	cercBurghiu = Cerc(centru_burghiuX, centru_burghiuY, radiusBurghiu);

}

void Player::updatePlayfieldSize (float coltStJosX, float coltStJosY, float coltDrSusX, float coltDrSusY, Visual2D *v2d) 
{
	origXPlayfield = coltStJosX;
	origYPlayfield = coltStJosY;
	widthPlayfield = coltDrSusX - coltStJosX;
	heightPlayfield = coltDrSusY - coltStJosY;
	playfield = v2d;
}

void Player::addPlayer2D(Visual2D *v2d)
{
	DrawingWindow::addObject2D_to_Visual2D(circ, v2d);
	DrawingWindow::addObject2D_to_Visual2D(circB, v2d);
	DrawingWindow::addObject2D_to_Visual2D(circC, v2d);
	DrawingWindow::addObject2D_to_Visual2D(circD, v2d);
	DrawingWindow::addObject2D_to_Visual2D(polygon, v2d);
	DrawingWindow::addObject2D_to_Visual2D(polygon2, v2d);
}

void Player::rotate(float u) 
{

	pasRotire += u;
	if (pasRotire > 2 * PI)
		pasRotire -= 2 * PI;
	else if (pasRotire < 0)
		pasRotire += 2 * PI;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(-origX, -origY);
	Transform2D::rotateMatrix(pasRotire);
	Transform2D::translateMatrix(origX, origY);

	Transform2D::translateMatrix(pasX, pasY);

	Transform2D::applyTransform(circ);
	Transform2D::applyTransform(circB);
	Transform2D::applyTransform(circC);
	Transform2D::applyTransform(circD);
	Transform2D::applyTransform(circE);
	Transform2D::applyTransform(circF);
	Transform2D::applyTransform(polygon);
	Transform2D::applyTransform(polygon2);
	if (weaponOn)
	{
		Transform2D::applyTransform(burghiu);
		Transform2D::applyTransform(burghiu1);
	}

}

void Player::move (int distance) {

	float nextPositionX = origX + pasX + cos(pasRotire);
	float nextPositionY = origY + pasY + sin(pasRotire);

	while (distance--) 	
	{

		if (origXPlayfield >= nextPositionX - radius || 
			origXPlayfield + widthPlayfield <= nextPositionX + radius || 
			origYPlayfield >= nextPositionY - radius ||
			origYPlayfield + heightPlayfield <= nextPositionY + radius
			) 
		{
			break;
		}

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-origX, -origY);
		Transform2D::rotateMatrix(pasRotire);
		Transform2D::translateMatrix(origX, origY);

		pasX += cos (pasRotire);
		pasY += sin (pasRotire);
		nextPositionX = origX + pasX + cos(pasRotire);
		nextPositionY = origY + pasY + sin(pasRotire);

		Transform2D::translateMatrix(pasX, pasY);

		Transform2D::applyTransform(circ);
		Transform2D::applyTransform(circB);
		Transform2D::applyTransform(circC);
		Transform2D::applyTransform(circD);
		Transform2D::applyTransform(circE);
		Transform2D::applyTransform(circF);
		Transform2D::applyTransform(polygon);
		Transform2D::applyTransform(polygon2);
		if (weaponOn)
		{
			Transform2D::applyTransform(burghiu);
			Transform2D::applyTransform(burghiu1);
		}

	}

}

void Player::toggleWeapon() 
{

	weaponOn = !weaponOn;

	if (weaponOn)
	{
		DrawingWindow::addObject2D_to_Visual2D(burghiu, playfield);
		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-origX, -origY);
		Transform2D::rotateMatrix(pasRotire);
		Transform2D::translateMatrix(origX, origY);

		Transform2D::translateMatrix(pasX, pasY);
		Transform2D::applyTransform(burghiu);
		Transform2D::applyTransform(burghiu1);
	}
	else
	{
		DrawingWindow::removeObject2D_from_Visual2D(burghiu, playfield);
		DrawingWindow::removeObject2D_from_Visual2D(burghiu1, playfield);
	}

}

bool Player::kills(Enemy *enemy) 
{

	if (!weaponOn)
	{
		return false;
	}

	float x, y;

	for (int i = 0; i < enemy->cercuri_coliziune.size(); i++) {

		x = cercBurghiu.getOriginX() + pasX;
		y = cercBurghiu.getOriginY() + pasY;

		// rotire cerc circumscris burghiului
		float rx, ry, rxp, ryp, xf, yf;
		rx = x - origX - pasX;
		ry = y - origY - pasY;
		float rx1, ry1;
		rx1 = rx;
		ry1 = ry;
		rxp = rx1 * cos(pasRotire) - ry1 * sin(pasRotire);
		ryp = rx1 * sin(pasRotire) + ry1 * cos(pasRotire);
		xf = rxp + origX + pasX;
		yf = ryp + origY + pasY;

		Cerc e = enemy->cercuri_coliziune[i];
		Cerc burghiuCurrent = Cerc(xf, yf, cercBurghiu.getRadius());
		Cerc enemyCurrent = 
			Cerc(e.getOriginX() + enemy->pasX, e.getOriginY() + enemy->pasY, e.getRadius());
		if (burghiuCurrent.intersects(enemyCurrent))
		{
			return true;
		}
	}

	return false;

}

bool Player::isKilled (Enemy *enemy)
{

	float x, y;

	for (int i = 0; i < enemy->cercuri_coliziune.size(); i++) {

		x = origX + pasX;
		y = origY + pasY;

		Cerc e = enemy->cercuri_coliziune[i];
		Cerc ship = Cerc(x, y, cercBurghiu.getRadius());
		Cerc enemyCurrent = 
			Cerc(e.getOriginX() + enemy->pasX, e.getOriginY() + enemy->pasY, e.getRadius());
		if (ship.intersects(enemyCurrent))
		{
			return true;
		}
	}

	return false;

}

void Player::removePlayer2D(Visual2D* v2d)
{

	DrawingWindow::removeObject2D_from_Visual2D(circ, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(circB, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(circC, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(circD, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(circE, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(circF, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(polygon, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(polygon2, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(burghiu, v2d);
	DrawingWindow::removeObject2D_from_Visual2D(burghiu1, v2d);

}

Player::~Player(void)
{
}
