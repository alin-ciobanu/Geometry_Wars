#include "Cerc.h"

Cerc::Cerc(void)
{
}

Cerc::Cerc(float x, float y, float radius)
{
	origX = x;
	origY = y;
	this->radius = radius;
}

float Cerc::getRadius()
{
	return radius;
}

void Cerc::setRadius(float radius)
{
	this->radius = radius;
}

void Cerc::setOrigin(float x, float y)
{
	origX = x;
	origY = y;
}

float Cerc::getOriginX()
{
	return origX;
}

float Cerc::getOriginY()
{
	return origY;
}

bool Cerc::intersects(Cerc c)
{

	float distance;
	distance = sqrt (pow((origX - c.getOriginX()), 2) + pow((origY - c.getOriginY()), 2));
	
	if (distance < 2 * radius)
	{
		return true;
	}

	return false;

}

Cerc::~Cerc(void)
{
}
