#pragma once

class Coordinates
{
protected:
	int _x;
	int _y;

	Coordinates(int x = 0, int y = 0) : _x(x), _y(y) { }

	inline int GetX() const { return _x; }
	inline int GetY() const { return _y; }

	inline void SetX(int x) { _x = x; }
	inline void SetY(int y) { _y = y; }
};
