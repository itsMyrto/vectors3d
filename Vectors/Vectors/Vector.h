#pragma once

#include <iostream>

using namespace std;

class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector();
	Vector(float, float, float);
	float GetX();
	float GetY();
	float GetZ();
	void SetX(float);
	void SetY(float);
	void SetZ(float);
	float AngleBetween2Vectors(Vector&,Vector&);
	Vector& CrossProduct(Vector&,Vector&);
	Vector& operator = (Vector&);
	Vector& operator += (Vector&);
	Vector& operator -= (Vector&);
	Vector& operator *= (Vector&);
	Vector& operator *= (int);
	Vector& operator ++ ();
	Vector& operator ++ (int);
	friend istream& operator >> (istream&, Vector&);
	float magnitude();
};

ostream& operator << (ostream&, Vector&);
Vector& operator + (Vector&, Vector&);
Vector& operator - (Vector&, Vector&);
float operator * (Vector&, Vector&);
Vector& operator * (Vector&, int);
Vector& operator * (int, Vector&);
bool operator == (Vector&, Vector&);
bool operator < (Vector&, Vector&);
bool operator > (Vector&, Vector&);

