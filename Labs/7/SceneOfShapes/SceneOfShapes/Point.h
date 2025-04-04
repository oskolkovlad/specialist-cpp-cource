#pragma once

#include "Shape.h"

class Point : public Shape
{
protected:
	int _x;
	int _y;

public:
	Point(int x = 0, int y = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), _x(x), _y(y) { }

	~Point() override
	{
		cout << "Point: сработал деструктор." << endl;
	}

	inline int GetX() const { return _x; }
	inline int GetY() const { return _y; }

	inline Point& SetX(int x) { _x = x; return *this; }
	inline Point& SetY(int y) { _y = y; return *this; }

	void Draw() const override;

	inline void MovePoint(int dX, int dY) { _x += dX; _y += dY; }
};
