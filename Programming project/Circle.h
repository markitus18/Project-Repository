#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point2f.h"
#include "Globals.h"
#include "Math.h"

template <class TYPE>
class Circle
{
public:
	Point2f <TYPE> position;
	TYPE radius;

public:
	Circle()
	{
		position.x = 0;
		position.y = 0;
		radius = 0;
	}

	Circle(TYPE x, int y, int _radius)
	{
		position.x = x;
		position.y = y;
		radius = _radius;
	}

	float Area() const
	{
		return PI * (radius ^2);
	}

	bool Intersect(const Circle& circle) const
	{
		return position.DistanceTo(circle.position) < radius + circle.radius;
	}
};

#endif //__CIRCLE_H__