#include "Vector4.h"

Vector4::Vector4(void)
{
	x = 0;
	y = 0;
	z = 0;
	w = 1.0f;
}

Vector4::Vector4(float xa, float ya, float za)
{
	x = xa;
	y = ya;
	z = za;
	w = 1.0f;
}

Vector4::Vector4(float xa, float ya, float za, float wa)
{
	x = xa;
	y = ya;
	z = za;
	w = wa;
}

Vector4::~Vector4(void)
{
}

Vector4 Vector4::operator =(Vector4& other)
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;

	return *this;
}

bool Vector4::operator ==(Vector4& other)
{
	if (x == other.x && y == other.y && z == other.z && w == other.w)
		return true;

	return false;
}

bool Vector4::operator !=(Vector4& other)
{
	if (x == other.x && y == other.y && z == other.z && w == other.w)
		return false;

	return true;
}

Vector4 Vector4::operator +(Vector4& other)
{
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4 Vector4::operator +=(Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;

	return *this;
}

Vector4 Vector4::operator -(Vector4& other)
{
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4 Vector4::operator -=(Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return *this;
}

Vector4 Vector4::operator *(float f)
{
	return Vector4(f*x, f*y, f*z, f*w);
}

Vector4 Vector4::operator *=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;

	return *this;
}

Vector4 Vector4::operator /(float f)
{
	return Vector4(x/f, y/f, z/f, w/f);
}

Vector4 Vector4::operator /=(float f)
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;

	return *this;
}

float Vector4::dot(Vector4* other)
{
	float dp = 0;
	dp += x * other->x;
	dp+= y * other->y;
	dp+=  z * other->z;
	dp+= w * other->w;

	return dp;
}

Vector4 Vector4::cross(Vector4& other)
{
	return Vector4(y*other.z - other.y*z, z*other.x - other.z*x, x*other.y - other.x*y);
}

float Vector4::magnitude()
{
	float f = 0.0f;

	f = sqrt(x*x + y*y + z*z + w*w);

	return f;
}

Vector4 Vector4::normalise()
{
	Vector4 vr;
	Vector4 v(x, y, z);
	vr = v / v.magnitude();
	return vr;
}


Vector4* Vector4::getNormal(Vector4* v1, Vector4* v2, Vector4* v3)
{
	Vector4* u = new Vector4(v2->x - v1->x, v2->y - v1->y, v2->z - v1->z);
	Vector4* v = new Vector4(v3->x - v1->x, v3->y - v1->y, v3->z - v1->z);
	
	return new Vector4(((u->y*v->z)-(u->z*v->y)),((u->z*v->x)-(u->x*v->z)),((u->x*v->y)-(u->y*v->x)));
}

void Vector4::print()
{
	printf("%.2f, %.2f, %.2f %.2f\n", x, y, z, w);
	printf("\n");
}