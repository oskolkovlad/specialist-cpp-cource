#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Shape
{
protected:
	string* _color;

public:
	const static char* DEFAULT_COLOR;

	Shape(string color = DEFAULT_COLOR)
	{
		_color = new string(color);
	}

	Shape(const char* color = DEFAULT_COLOR)
	{
		_color = new string(color);
	}

	Shape(const Shape& item)
	{
		_color = new string(item.GetColor());
	}

	Shape& operator =(const Shape& item)
	{
		_color = new string(item.GetColor());
		return *this;
	}

	virtual ~Shape()
	{
		cout << "Shape: сработал деструктор." << endl;

		delete _color;
	}

	inline string GetColor() const { return *_color; }

	virtual void Draw() const = 0; // Абстрактный метод, из-за него класс Shape также является абстрактным.
};
