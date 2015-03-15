#ifndef __Point2f_H__
#define __Point2f_H__


#include <stdlib.h>
#include <math.h>

template <class TYPE>

class Point2f
{

public:

	TYPE x;
	TYPE y;


public:

	Point2f Point2f::operator- (const Point2f& point) const
	{
		Point2f tmp;
		tmp.x = x - point.x;
		tmp.y = y - point.y;
		return tmp;
	}

	Point2f Point2f::operator+ (const Point2f& point) const
	{
		Point2f tmp;
		tmp.x = x + point.x;
		tmp.y = y + point.y;
		return tmp;
	}

	Point2f Point2f::operator += (const Point2f& point)
	{
		x = x + point.x;
		y = y + point.y;
		return *this;
	}

	Point2f Point2f::operator -= (const Point2f& point)
	{
		x = x - point.x;
		y = y - point.y;
		return *this;
	}

	bool Point2f::operator == (const Point2f& point) const
	{
		return (x == point.x && y == point.y);
	}

	bool Point2f::operator != (const Point2f& point) const
	{
		return !(x == point.x && y == point.y);
	}

	void Point2f::SetZero()
	{
		x = y = 0;
	}

	bool Point2f::IsZero() const
	{
		return (x == 0 && y == 0);
	}

	TYPE Point2f::DistanceTo(const Point2f& point) const
	{
		TYPE value = ((point.x - x) * (point.x - x)) + (point.y - y) * (point.y - y);
		return sqrt(value);
	}

};


#endif //__fPoint2f_H__