#pragma once

#include "Shape.h"
#include "Coordinates.h"
#include "IMoveable.h"

class Point :
	public IMoveable,
	public virtual Shape,
	private Coordinates
{
public:
	Point(int x = 0, int y = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), Coordinates(x, y){ }

	~Point() override
	{
		cout << "Point: сработал деструктор." << endl;
	}

	void Draw() const override;

	inline void MoveBy(int dX, int dY) override { this->Coordinates::_x += dX; this->Coordinates::_y += dY; }
	inline void MoveTo(int x, int y) override { this->SetX(x); this->SetY(y); }
};
