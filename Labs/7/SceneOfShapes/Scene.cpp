#include "Scene.h"

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