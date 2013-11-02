#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Vector4
{
public:
	
	float x;
	float y;
	float z;
	float w;

	Vector4(void);
	Vector4(float, float, float);
	Vector4(float, float, float, float);
	~Vector4(void);
	
	Vector4 operator =(Vector4&);
	bool operator ==(Vector4&);
	bool operator !=(Vector4&);
	Vector4 operator +(Vector4&);
	Vector4 operator +=(Vector4&);
	Vector4 operator -(Vector4&);
	Vector4 operator -=(Vector4&);
	Vector4 operator *(float);
	Vector4 operator *=(float);
	Vector4 operator/(float);
	Vector4 operator  /=(float);

	float dot(Vector4*);
	Vector4 cross(Vector4&);
	float magnitude();
	Vector4 normalise();
	Vector4* getNormal(Vector4*, Vector4*, Vector4*);

	void print();
};

#endif