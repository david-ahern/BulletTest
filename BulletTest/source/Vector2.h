#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Vector2
{
public:
	
	float x;
	float y;

	Vector2(void);
	Vector2(float);
	Vector2(float, float);
	~Vector2(void);
	
	Vector2 operator =(Vector2&);
	bool operator ==(Vector2&);
	bool operator !=(Vector2&);
	Vector2 operator +(Vector2&);
	Vector2 operator +=(Vector2&);
	Vector2 operator -(Vector2&);
	Vector2 operator -=(Vector2&);
	Vector2 operator *(float);
	Vector2 operator *=(float);
	Vector2 operator /(float);
	Vector2 operator  /=(float);

	float dot(Vector2&);
	float magnitude();
	Vector2 normalise();	

	void print();
};