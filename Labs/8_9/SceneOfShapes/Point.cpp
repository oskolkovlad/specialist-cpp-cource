#include "Point.h"

void Point::Draw() const
{
	cout << "(" << this->GetX() << ", " << this->GetY() << "); Color = " << this->GetColor() << endl;
}