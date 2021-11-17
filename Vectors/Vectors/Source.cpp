#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{

	Vector v1(1, 1, 1), v2, v3, v4, v5, v6, v7;
	float InnerP;

	cin >> v2;

	v3 = v1 + v2;
	v4 = v1 - v2;
	v5 = 2 * v1;
	v6 = v2 * 3;
	v7 = v7.CrossProduct(v1, v2);
	InnerP = v1 * v2;

	cout << "The Inner Product is: " << InnerP << endl;

	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v4 << endl;
	cout << v5 << endl;
	cout << v6 << endl;
	cout << v7 << endl;

	return 0;
}