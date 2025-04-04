#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Scene.h"

// В рамках данного проекта реализована лабораторная работа по модулю 7.

int main()
{
    system("chcp 1251 > nul");

    Point* point = new Point(10, 100);
    point->Draw();

    Shape* shape = point;
    shape->Draw();

    Point* pointCasted = dynamic_cast<Point*>(shape);
    shape->Draw();

    cout << endl;

    Circle* circle1 = new Circle(1, 1, 5, "Red");
    Circle* circle2 = new Circle(6, 7, 20, "Green");
    circle1->Draw();
    circle2->Draw();

    cout << endl;

    Scene* scene = new Scene();
    scene->AddShape(point);
    scene->AddShape(circle1);
    scene->AddShape(circle2);
    scene->Scale(2.5);
    scene->MoveBy(5, 10);
    scene->Draw();

    cout << endl;

    //***//
    
    delete scene;
}
