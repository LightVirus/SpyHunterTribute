// ----------------------------------------------------
// Point class    -----------
// ----------------------------------------------------

#ifndef __POINT_H__
#define __POINT_H__

template<class TYPE>
class Point
{
public:
	float distance;
	TYPE x, y;

	Point()
	{}
	Point(TYPE x, TYPE y) : x(x), y(y)
	{}

	// Operators ------------------------------------------------
	Point operator -(const Point &v) const
	{
		p2Vector2 r;

		r.x = x - v.x;
		r.y = y - v.y;

		return(r);
	}

	Point operator + (const Point &v) const
	{
		p2Vector2 r;

		r.x = x + v.x;
		r.y = y + v.y;

		return(r);
	}

	const Point& operator -=(const Point &v)
	{
		x -= v.x;
		y -= v.y;

		return(*this);
	}

	const Point& operator +=(const Point &v)
	{
		x += v.x;
		y += v.y;

		return(*this);
	}

	bool operator ==(const Point& v) const
	{
		return (x == v.x && y == v.y);
	}

	bool operator !=(const Point& v) const
	{
		return (x != v.x || y != v.y);
	}

	// Utils ------------------------------------------------
	bool IsZero() const
	{
		return (x == 0 && y == 0);
	}

	Point& SetToZero()
	{
		x = y = 0;
		return(*this);
	}

	Point& Negate()
	{
		x = -x;
		y = -y;

		return(*this);
	}

	Point& NextPoint(const Point& dest, float speed)
	{
		float xDistance = dest.x - x;
		float yDistance = dest.y - y;
		distance = sqrt((xDistance*xDistance) + (yDistance*yDistance));
		if (distance > 1.0)
		{
			x += xDistance * speed;
			y += yDistance * speed;
		}

		return(*this);
	}

	// Distances ---------------------------------------------
	TYPE DistanceTo(const Point& v) const
	{
		TYPE fx = x - v.x;
		TYPE fy = y - v.y;

		return sqrt((fx*fx) + (fy*fy));
	}
};

typedef Point<int> iPoint;
typedef Point<float> fPoint;

#endif // __POINT_H__