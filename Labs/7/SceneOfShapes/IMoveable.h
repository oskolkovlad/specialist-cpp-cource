#pragma once

// Абстрактный класс-интерфейс.
class IMoveable
{
public:
	virtual void MoveBy(int dX, int dY) = 0;
	virtual void MoveTo(int x, int y) = 0;
};
