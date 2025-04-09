#pragma once

#include "Shape.h"
#include "IScaleable.h"
#include "List.h"

class Scene : public IScaleable
{
private:
	List<Shape>* _collection;

public:
	Scene() { this->_collection = new List<Shape>(); }

	virtual ~Scene()
	{
		cout << "Scene: сработал деструктор." << endl;
		delete _collection;
	}

	void Add(Shape* item);
	void Clear();

	void Draw() const;
	void Scale(double factor) override;
	void MoveBy(int dX, int dY);
};
