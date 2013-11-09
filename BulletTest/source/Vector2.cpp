#include "Vector2.h"

Vector2::Vector2(void)
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float xa)
{
	x = xa;
	y = 0.0f;
}

Vector2::Vector2(float xa, float ya)
{
	x = xa;
	y = ya;
}

Vector2::~Vector2(void)
{
}

Vector2 Vector2::operator =(Vector2& other)
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;

	return *this;
}

bool Vector2::operator ==(Vector2& other)
{
	if (x == other.x && y == other.y)
		return true;

	return false;
}

bool Vector2::operator !=(Vector2& other)
{
	if (x == other.x && y == other.y)
		return false;

	return true;
}

Vector2 Vector2::operator +(Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator +=(Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator -(Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator -=(Vector2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2 Vector2::operator *(float f)
{
	return Vector2(f*x, f*y);
}

Vector2 Vector2::operator *=(float f)
{
	x *= f;
	y *= f;

	return *this;
}

Vector2 Vector2::operator /(float f)
{
	return Vector2(x/f, y/f);
}

Vector2 Vector2::operator /=(float f)
{
	x /= f;
	y /= f;

	return *this;
}

float Vector2::dot(Vector2& other)
{
	return x * other.x + y * other.y;
}

float Vector2::magnitude()
{
	float f = 0.0f;

	f = sqrt(x*x + y*y);

	return f;
}

Vector2 Vector2::normalise()
{
	Vector2 vr;
	Vector2 v(x, y);
	vr = v / v.magnitude();
	return vr;
}

void Vector2::print()
{
	printf("%.2f, %.2f\n", x, y);
	printf("\n");
}