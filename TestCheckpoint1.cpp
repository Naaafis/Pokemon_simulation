#include <iostream>
#include <cmath>
using namespace std;

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"



// main code goes here
int main()
{
	Point2D p1;
	Vector2D v1;
	cout << "create a point: " << endl;
	cin >> p1.x >> p1.y;
	cout << "create a vector: " << endl;
	cin >> v1.x >> v1.y;

	Point2D p2 = Point2D(1.0, 1.0);

	double d = GetDistanceBetween(p1, p2);

	cout << "addition: " << p1 + v1 << endl;
	cout << "cout (points): " << p1 << ", " << p2 << endl;
	cout << "distance between points: " << d << endl;
	cout << "subtraction: " << p1 - p2 << endl;
	cout << "multiplication: " << v1 * 2 << endl;
	cout << "division: " << v1 / 2 << endl;
	cout << "cout (vector): " << v1 << endl;

	GameObject newobj = GameObject(p1, 5, 'P');
	newobj.ShowStatus();

	return 0;
}