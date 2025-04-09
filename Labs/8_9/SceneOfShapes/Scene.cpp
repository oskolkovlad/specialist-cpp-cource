#include "Scene.h"
#include "IScaleable.h"
#include "IMoveable.h"

void Scene::Add(Shape* item)
{
	_collection->Add(item);
}

void Scene::Clear()
{
	_collection->Clear();
}

void Scene::Draw() const
{
	cout << "Start draw Scene..." << endl;

	_collection->Start();

	Shape* currentShape;

	while ((currentShape = _collection->Next()) != nullptr)
	{
		currentShape->Draw();
	}

	cout << "End draw Scene." << endl;
}

void Scene::Scale(double factor)
{
	_collection->Start();

	Shape* currentShape;

	while ((currentShape = _collection->Next()) != nullptr)
	{
		IScaleable* item = dynamic_cast<IScaleable*>(currentShape);

		if (item != nullptr)
			item->Scale(factor);
	}
}

void Scene::MoveBy(int dX, int dY)
{
	_collection->Start();

	Shape* currentShape;

	while ((currentShape = _collection->Next()) != nullptr)
	{
		IMoveable* item = dynamic_cast<IMoveable*>(currentShape);

		if (item != nullptr)
			item->MoveBy(dX, dY);
	}
}
