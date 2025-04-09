#pragma once

// Абстрактный класс-интерфейс.
class IScaleable
{
public:
	virtual void Scale(double factor) = 0;
};