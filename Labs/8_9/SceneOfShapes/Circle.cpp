#include "Circle.h"

void Circle::Draw() const
{
	cout << "Start = (" << this->GetX() << ", " << this->GetY() << "); Radius = " << this->GetRadius() << "; Color = " << this->GetColor() << endl;
}