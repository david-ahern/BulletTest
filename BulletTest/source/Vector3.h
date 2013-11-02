#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "btBulletDynamicsCommon.h"

class Vector3
{
public:
	
	float x;
	float y;
	float z;

	Vector3(void);
	Vector3(float, float);
	Vector3(float, float, float);
	~Vector3(void);
	
	Vector3 operator =(Vector3&);
	Vector3 operator =(btVector3&);
	bool operator ==(Vector3&);
	bool operator !=(Vector3&);
	Vector3 operator +(Vector3&);
	Vector3 operator +=(Vector3&);
	Vector3 operator -(Vector3&);
	Vector3 operator -=(Vector3&);
	Vector3 operator *(float);
	Vector3 operator *=(float);
	Vector3 operator /(float);
	Vector3 operator  /=(float);

	float dot(Vector3*);
	Vector3 cross(Vector3&);
	float magnitude();
	Vector3 normalise();
	Vector3* getNormal(Vector3*, Vector3*, Vector3*);

	void print();
};

#endif