#include "Vector.h"
#include <cmath>

Vector::Vector()
{
	x = y = z = 0;
}

Vector::Vector(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

float Vector::GetX()
{
	return x;
}

float Vector::GetY()
{
	return y;
}

float Vector::GetZ()
{
	return z;
}

void Vector::SetX(float a)
{
	x = a;
}

void Vector::SetY(float a)
{
	y = a;
}

void Vector::SetZ(float a)
{
	z = a;
}

Vector& Vector::operator = (Vector& obj)
{
	this->x = obj.GetX();
	this->y = obj.GetY();
	this->z = obj.GetZ();
	return *this;
}

istream& operator >> (istream& i, Vector& obj)
{
	cout << "Enter three values, one for X, one for Y and one for Z: " << endl;
	i >> obj.x >> obj.y >> obj.z;
	return i;
}

ostream& operator << (ostream& o, Vector& obj)
{
	o << "Vector: (" << obj.GetX() << "," << obj.GetY() << "," << obj.GetZ() << ")" << endl;
	return o;
}

Vector& operator + (Vector& obj1, Vector& obj2)
{
	Vector* temp;

	temp = new Vector();

	temp->SetX(obj1.GetX() + obj2.GetX());
	temp->SetY(obj1.GetY() + obj2.GetY());
	temp->SetZ(obj1.GetZ() + obj2.GetZ());
	return *temp;
}

Vector& operator - (Vector& obj1, Vector& obj2)
{
	Vector* temp;
	temp = new Vector();
	temp->SetX(obj1.GetX() - obj2.GetX());
	temp->SetY(obj1.GetY() - obj2.GetY());
	temp->SetZ(obj1.GetZ() - obj2.GetZ());
	return *temp;
}

float operator * (Vector& obj1, Vector& obj2)
{
	return (obj1.GetX() * obj2.GetX() + obj1.GetY() * obj2.GetY() + obj1.GetZ() * obj2.GetZ());
}

Vector& operator * (Vector& obj, int l)
{
	Vector* temp;
	temp = new Vector();
	temp->SetX(obj.GetX() * l);
	temp->SetY(obj.GetY() * l);
	temp->SetZ(obj.GetZ() * l);
	return *temp;
}

Vector& operator * (int l, Vector& obj)
{
	Vector* temp;
	temp = new Vector();
	temp->SetX(obj.GetX() * l);
	temp->SetY(obj.GetY() * l);
	temp->SetZ(obj.GetZ() * l);
	return *temp;
}

float Vector::magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

bool operator == (Vector& obj1, Vector& obj2)
{
	if (obj1.GetX() == obj2.GetX() && obj1.GetY() == obj2.GetY() && obj1.GetZ() == obj2.GetZ())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator < (Vector& obj1, Vector& obj2)
{
	if (obj1.magnitude() < obj2.magnitude())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator > (Vector& obj1, Vector& obj2)
{
	if (obj1.magnitude() > obj2.magnitude())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vector& Vector::operator += (Vector& obj1)
{
	this->x += obj1.GetX();
	this->y += obj1.GetY();
	this->z += obj1.GetZ();
	return *this;
}

Vector& Vector::operator -= (Vector& obj1)
{
	this->x -= obj1.GetX();
	this->y -= obj1.GetY();
	this->z -= obj1.GetZ();
	return *this;
}

Vector& Vector::operator *= (Vector& obj1)
{
	this->x *= obj1.GetX();
	this->y *= obj1.GetY();
	this->z *= obj1.GetZ();
	return *this;
}

Vector& Vector::operator *= (int l)
{
	this->x *= l;
	this->y *= l;
	this->z *= l;
	return *this;
}

Vector& Vector::operator ++ ()
{
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

Vector& Vector::operator ++ (int)
{
	Vector* temp;
	temp = new Vector(*this);
	(*this)++;
	return *temp;
}

Vector& Vector::CrossProduct(Vector& obj1,Vector& obj2)
{
	Vector* temp;
	temp = new Vector();
	temp->SetX(obj1.GetY() * obj2.GetZ() - obj1.GetZ() * obj2.GetY());
	temp->SetY(obj1.GetZ() * obj2.GetX() - obj1.GetX() * obj2.GetZ());
	temp->SetY(obj1.GetX() * obj2.GetY() - obj1.GetY() * obj2.GetX());
	return *temp;
}

float Vector::AngleBetween2Vectors(Vector& obj1, Vector& obj2)
{
	return acos((obj1.GetX() * obj2.GetX() + obj1.GetY() * obj2.GetY() + obj1.GetZ() * obj2.GetZ()) / (obj1.magnitude() * obj2.magnitude()));
}