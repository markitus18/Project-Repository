#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "Point2f.h"


class Projectile
{
public:

	float x;
	float y;

	float speedx;
	float speedy;

/*
Projectile(pointx, pointy, speedx, speedy)
	{
		<int>point.x = _pointx;
		<int>point.y = _pointy;

		speedx = _speedx;
		speedy = _speedy;
	}
*/

	Point2f<float>& GetCurrentPosition(const float time) const
	{
		Point2f<float> point;
		point.x = x + speedx * time;
		point.y = y + speedy * time;

		return point;
	}
};

#endif //__PROJECTILE_H__