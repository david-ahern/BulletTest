#include "Vector3.h"

Vector3::Vector3(void)
{
	x = 0;
	y = 0;
	z = 1.0f;

}

Vector3::Vector3(float xa, float ya)
{
	x = xa;
	y = ya;
	z = 1.0f;
}

Vector3::Vector3(float xa, float ya, float za)
{
	x = xa;
	y = ya;
	z = za;
}

Vector3::~Vector3(void)
{
}

Vector3 Vector3::operator =(Vector3& other)
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator =(btVector3& other)
{
	x = other.x();
	y = other.y();
	z = other.z();

	return *this;
}

bool Vector3::operator ==(Vector3& other)
{
	if (x == other.x && y == other.y && z == other.z)
		return true;

	return false;
}

bool Vector3::operator !=(Vector3& other)
{
	if (x == other.x && y == other.y && z == other.z)
		return false;

	return true;
}

Vector3 Vector3::operator +(Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator +=(Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector3 Vector3::operator -(Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator -=(Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

Vector3 Vector3::operator *(float f)
{
	return Vector3(f*x, f*y, f*z);
}

Vector3 Vector3::operator *=(float f)
{
	x *= f;
	y *= f;
	z *= f;

	return *this;
}

Vector3 Vector3::operator /(float f)
{
	return Vector3(x/f, y/f, z/f);
}

Vector3 Vector3::operator /=(float f)
{
	x /= f;
	y /= f;
	z /= f;

	return *this;
}

float Vector3::dot(Vector3* other)
{
	return x * other->x + y * other->y + z * other->z;
}

Vector3 Vector3::cross(Vector3& other)
{
	return Vector3(y*other.z - other.y*z, z*other.x - other.z*x, x*other.y - other.x*y);
}

float Vector3::magnitude()
{
	float f = 0.0f;

	f = sqrt(x*x + y*y + z*z);

	return f;
}

Vector3 Vector3::normalise()
{
	Vector3 vr;
	Vector3 v(x, y, z);
	vr = v / v.magnitude();
	return vr;
}

Vector3* Vector3::getNormal(Vector3* v1, Vector3* v2, Vector3* v3)
{
	Vector3* u = new Vector3(v2->x - v1->x, v2->y - v1->y, v2->z - v1->z);
	Vector3* v = new Vector3(v3->x - v1->x, v3->y - v1->y, v3->z - v1->z);
	
	return new Vector3((u->x*v->x)-(u->z*v->y),(u->z*v->x)-(u->x*v->z),(u->x*v->y)-(u->y*v->x));
}

void Vector3::print()
{
	printf("%.2f, %.2f, %.2f\n", x, y, z);
	printf("\n");
}