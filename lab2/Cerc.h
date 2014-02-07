#pragma once
#include <math.h>

class Cerc
{
private:
	float origX, origY;
	float radius;
public:
	Cerc(void);
	Cerc(float, float, float);
	void setRadius(float);
	float getRadius(void);
	void setOrigin(float, float);
	float getOriginX(void);
	float getOriginY(void);
	bool intersects(Cerc);
	~Cerc(void);
};

