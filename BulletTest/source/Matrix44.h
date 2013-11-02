#ifndef _MATRIX44_H_
#define _MATRIX44

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Vector4tag{
				float x;
				float y;
				float z;
				float w;
			} Vector44;

class Matrix44
{
public:
	
	float m[16];

	Matrix44(void);
	Matrix44(float, float, float);

	void Identity();	

	~Matrix44(void);

	float* getMatrix();

	void Scale(float, float, float);
	
	void rotateX(float);
	void rotateY(float);
	void rotateZ(float);	
	void translate(float, float, float);
	void transpose(void);

	Matrix44 operator =(Matrix44&);
	Matrix44 operator =(float[16]);
	bool operator ==(Matrix44&);
	bool operator !=(Matrix44&);
	Matrix44* operator *(Matrix44&);
	Matrix44 operator *=(Matrix44&);
	Matrix44 operator *(float);
	Matrix44 operator *=(float);
	Matrix44* operator +(Matrix44&);
	Matrix44 operator +=(Matrix44&);
	Matrix44 operator -(Matrix44&);
	Matrix44 operator -=(Matrix44&);

	void print();
};

#endif