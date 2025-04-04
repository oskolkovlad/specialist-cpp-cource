#include "Scene.h"
#include "IScaleable.h"
#include "IMoveable.h"

bool Scene::AddShape(const Shape* item)
{
	if (_currentIndex >= MAX_SCENE_SIZE)
		return false;

	_sceneItems[_currentIndex++] = const_cast<Shape*>(item);
	return true;
}

void Scene::Clear()
{
	for (int index = 0; index < _currentIndex; index++)
	{
		delete _sceneItems[index];
	}

	_currentIndex = 0;
}

void Scene::Draw() const
{
	cout << "Start draw Scene..." << endl;

	for (int index = 0; index < _currentIndex; index++)
	{
		_sceneItems[index]->Draw();
	}

	cout << "End draw Scene." << endl;
}

void Scene::Scale(double factor)
{
	for (int index = 0; index < _currentIndex; index++)
	{
		IScaleable* item = dynamic_cast<IScaleable*>(_sceneItems[index]);
		
		if (item != NULL)
			item->Scale(factor);
	}
}

void Scene::MoveBy(int dX, int dY)
{
	for (int index = 0; index < _currentIndex; index++)
	{
		IMoveable* item = dynamic_cast<IMoveable*>(_sceneItems[index]);
		
		if (item != NULL)
			item->MoveBy(dX, dY);
	}
}
