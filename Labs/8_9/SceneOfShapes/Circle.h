#pragma once

#include "Shape.h"
#include "Coordinates.h"
#include "IScaleable.h"
#include "IMoveable.h"

class Circle :
	public IScaleable,
	public IMoveable,
	public virtual Shape,
	private Coordinates
{
protected:
	double _r;

public:
	Circle(int x = 0, int y = 0, double r = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), Coordinates(x, y), _r(r) { }

	~Circle() override
	{
		cout << "Circle: сработал деструктор." << endl;
	}

	inline double GetRadius() const { return _r; }
	inline Circle& SetRadius(double r) { _r = r; return *this; }

	void Draw() const override;

	inline void Scale(double factor) override { _r *= factor; }

	inline void MoveBy(int dX, int dY) override { this->Coordinates::_x += dX; this->Coordinates::_y += dY; }
	inline void MoveTo(int x, int y) override { this->SetX(x); this->SetY(y); }
};
