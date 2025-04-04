#pragma once

#include "Shape.h"

class Circle : public Shape
{
protected:
	int _x;
	int _y;
	int _r;

public:
	Circle(int x = 0, int y = 0, int r = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), _x(x), _y(y), _r(r) { }

	~Circle() override
	{
		cout << "Circle: сработал деструктор." << endl;
	}

	inline int GetX() const { return _x; }
	inline int GetY() const { return _y; }
	inline int GetRadius() const { return _r; }

	inline Circle& SetX(int x) { _x = x; return *this; }
	inline Circle& SetY(int y) { _y = y; return *this; }
	inline Circle& SetRadius(int r) { _r = r; return *this; }

	void Draw() const override;

	inline void Scale(double factor) { _r *= factor; }
};
