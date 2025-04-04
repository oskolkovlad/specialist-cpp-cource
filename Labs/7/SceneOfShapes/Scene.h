#pragma once

#include "Shape.h"
#include "IScaleable.h"

const int MAX_SCENE_SIZE = 10;

class Scene : public IScaleable
{
private:
	int _currentIndex;
	Shape** _sceneItems;

public:
	Scene() : _currentIndex(0)
	{
		_sceneItems = new Shape*[MAX_SCENE_SIZE];
	}

	virtual ~Scene()
	{
		cout << "Scene: сработал деструктор." << endl;

		Clear();
		delete[] _sceneItems;
	}

	bool AddShape(const Shape* item);
	void Clear();

	void Draw() const;
	void Scale(double factor) override;
	void MoveBy(int dX, int dY);
};
