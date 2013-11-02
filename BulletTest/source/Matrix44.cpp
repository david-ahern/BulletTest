#include "Matrix44.h"


Matrix44::Matrix44(void)
{
	Identity();
}

Matrix44::Matrix44(float x, float y, float z)
{
	Identity();
	Scale(x, y, z);
}

Matrix44::~Matrix44(void)
{
}

float* Matrix44::getMatrix()
{
	return m;
}

void Matrix44::Identity()
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = 1.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix44::Scale(float x, float y, float z)
{
	m[0] = x;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = y;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = z;
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix44::rotateX(float angle)
{
	float sintheta, costheta;
	sintheta = (float)sin(angle*0.01745329252);
	costheta = (float)cos(angle*0.01745329252);

	m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;

    m[4] = 0.0f;
    m[5] = costheta;
    m[6] = sintheta;
    m[7] = 0.0f;

    m[8] = 0.0f;
    m[9] = -sintheta;
    m[10] = costheta;
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

void Matrix44::rotateY(float angle)
{
	float sintheta, costheta;
	sintheta = (float)sin(angle*0.01745329252);
	costheta = (float)cos(angle*0.01745329252);

	m[0] = costheta;
    m[1] = 0.0f;
    m[2] = -sintheta;
    m[3] = 0.0f;

    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;

    m[8] = sintheta;
    m[9] = 0.0f;
    m[10] = costheta;
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

void Matrix44::rotateZ(float angle)
{
	float sintheta, costheta;
	sintheta = (float)sin(angle*0.01745329252);
	costheta = (float)cos(angle*0.01745329252);

	m[0] = costheta;
	m[1] = sintheta;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = -sintheta;
	m[5] = costheta;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix44::translate(float x, float y, float z)
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = 1.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;

	m[12] += x;
	m[13] += y;
	m[14] += z;
	m[15] = 1.0f;
}

void Matrix44::transpose(void)
{
	Matrix44 temp;

	temp.m[0] = m[0];
	temp.m[1] = m[1];
	temp.m[2] = m[2];
	temp.m[3] = m[3];

	temp.m[4] = m[4];
	temp.m[5] = m[5];
	temp.m[6] = m[6];
	temp.m[7] = m[7];

	temp.m[8] = m[8];
	temp.m[9] = m[9];
	temp.m[10] = m[10];
	temp.m[11] = m[11];

	temp.m[12] = m[12];
	temp.m[13] = m[13];
	temp.m[14] = m[14];
	temp.m[15] = m[15];



	m[0] = temp.m[0];
	m[1] = temp.m[4];
	m[2] = temp.m[8];
	m[3] = temp.m[12];

	m[4] = temp.m[1];
	m[5] = temp.m[5];
	m[6] = temp.m[9];
	m[7] = temp.m[13];

	m[8] = temp.m[2];
	m[9] = temp.m[6];
	m[10] = temp.m[10];
	m[11] = temp.m[14];

	m[12] = temp.m[3];
	m[13] = temp.m[7];
	m[14] = temp.m[11];
	m[15] = temp.m[15];
}

Matrix44 Matrix44::operator =(Matrix44& other)
{
	if (this == &other)
		return *this;

	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];

	m[4] = other.m[4];
	m[5] = other.m[5];
	m[6] = other.m[6];
	m[7] = other.m[7];

	m[8] = other.m[8];
	m[9] = other.m[9];
	m[10] = other.m[10];
	m[11] = other.m[11];

	m[12] = other.m[12];
	m[13] = other.m[13];
	m[14] = other.m[14];
	m[15] = other.m[15];

	return *this;
}

Matrix44 Matrix44::operator =(float other[16])
{
	m[0] = other[0];
	m[1] = other[1];
	m[2] = other[2];
	m[3] = other[3];

	m[4] = other[4];
	m[5] = other[5];
	m[6] = other[6];
	m[7] = other[7];

	m[8] = other[8];
	m[9] = other[9];
	m[10] = other[10];
	m[11] = other[11];

	m[12] = other[12];
	m[13] = other[13];
	m[14] = other[14];
	m[15] = other[15];

	return *this;
}

bool Matrix44::operator ==(Matrix44& other)
{
	if (m[0] == other.m[0] &&
		m[1] == other.m[1] &&
		m[2] == other.m[2] &&
		m[3] == other.m[3] &&
		m[4] == other.m[4] &&
		m[5] == other.m[5] &&
		m[6] == other.m[6] &&
		m[7] == other.m[7] &&
		m[8] == other.m[8] &&
		m[9] == other.m[9] &&
		m[10] == other.m[10] &&
		m[11] == other.m[11] &&
		m[12] == other.m[12] &&
		m[13] == other.m[13] &&
		m[14] == other.m[14] &&
		m[15] == other.m[15])
		return true;

	return false;
}

bool Matrix44::operator !=(Matrix44& other)
{
	if (m[0] == other.m[0] &&
		m[1] == other.m[1] &&
		m[2] == other.m[2] &&
		m[3] == other.m[3] &&
		m[4] == other.m[4] &&
		m[5] == other.m[5] &&
		m[6] == other.m[6] &&
		m[7] == other.m[7] &&
		m[8] == other.m[8] &&
		m[9] == other.m[9] &&
		m[10] == other.m[10] &&
		m[11] == other.m[11] &&
		m[12] == other.m[12] &&
		m[13] == other.m[13] &&
		m[14] == other.m[14] &&
		m[15] == other.m[15])
		return false;

	return true;
}

Matrix44* Matrix44::operator *(Matrix44& other)
{
	Matrix44* result = new Matrix44();

	result->m[0] = m[0]*other.m[0] + m[4]*other.m[1] + m[8]*other.m[2] + m[12]*other.m[3];
    result->m[1] = m[1]*other.m[0] + m[5]*other.m[1] + m[9]*other.m[2] + m[13]*other.m[3];
    result->m[2] = m[2]*other.m[0] + m[6]*other.m[1] + m[10]*other.m[2] + m[14]*other.m[3];
    result->m[3] = m[3]*other.m[0] + m[7]*other.m[1] + m[11]*other.m[2] + m[15]*other.m[3];

    result->m[4] = m[0]*other.m[4] + m[4]*other.m[5] + m[8]*other.m[6] + m[12]*other.m[7];
    result->m[5] = m[1]*other.m[4] + m[5]*other.m[5] + m[9]*other.m[6] + m[13]*other.m[7];
    result->m[6] = m[2]*other.m[4] + m[6]*other.m[5] + m[10]*other.m[6] + m[14]*other.m[7];
    result->m[7] = m[3]*other.m[4] + m[7]*other.m[5] + m[11]*other.m[6] + m[15]*other.m[7];

    result->m[8] = m[0]*other.m[8] + m[4]*other.m[9] + m[8]*other.m[10] + m[12]*other.m[11];
    result->m[9] = m[1]*other.m[8] + m[5]*other.m[9] + m[9]*other.m[10] + m[13]*other.m[11];
    result->m[10] = m[2]*other.m[8] + m[6]*other.m[9] + m[10]*other.m[10] + m[14]*other.m[11];
    result->m[11] = m[3]*other.m[8] + m[7]*other.m[9] + m[11]*other.m[10] + m[15]*other.m[11];

    result->m[12] = m[0]*other.m[12] + m[4]*other.m[13] + m[8]*other.m[14] + m[12]*other.m[15];
    result->m[13] = m[1]*other.m[12] + m[5]*other.m[13] + m[9]*other.m[14] + m[13]*other.m[15];
    result->m[14] = m[2]*other.m[12] + m[6]*other.m[13] + m[10]*other.m[14] + m[14]*other.m[15];
    result->m[15] = m[3]*other.m[12] + m[7]*other.m[13] + m[11]*other.m[14] + m[15]*other.m[15];
	
    return result;
}

Matrix44 Matrix44::operator *=(Matrix44& other)
{
	Matrix44 result;

	result.m[0] = m[0]*other.m[0] + m[4]*other.m[1] + m[8]*other.m[2] + m[12]*other.m[3];
    result.m[1] = m[1]*other.m[0] + m[5]*other.m[1] + m[9]*other.m[2] + m[13]*other.m[3];
    result.m[2] = m[2]*other.m[0] + m[6]*other.m[1] + m[10]*other.m[2] + m[14]*other.m[3];
    result.m[3] = m[3]*other.m[0] + m[7]*other.m[1] + m[11]*other.m[2] + m[15]*other.m[3];

    result.m[4] = m[0]*other.m[4] + m[4]*other.m[5] + m[8]*other.m[6] + m[12]*other.m[7];
    result.m[5] = m[1]*other.m[4] + m[5]*other.m[5] + m[9]*other.m[6] + m[13]*other.m[7];
    result.m[6] = m[2]*other.m[4] + m[6]*other.m[5] + m[10]*other.m[6] + m[14]*other.m[7];
    result.m[7] = m[3]*other.m[4] + m[7]*other.m[5] + m[11]*other.m[6] + m[15]*other.m[7];

    result.m[8] = m[0]*other.m[8] + m[4]*other.m[9] + m[8]*other.m[10] + m[12]*other.m[11];
    result.m[9] = m[1]*other.m[8] + m[5]*other.m[9] + m[9]*other.m[10] + m[13]*other.m[11];
    result.m[10] = m[2]*other.m[8] + m[6]*other.m[9] + m[10]*other.m[10] + m[14]*other.m[11];
    result.m[11] = m[3]*other.m[8] + m[7]*other.m[9] + m[11]*other.m[10] + m[15]*other.m[11];

    result.m[12] = m[0]*other.m[12] + m[4]*other.m[13] + m[8]*other.m[14] + m[12]*other.m[15];
    result.m[13] = m[1]*other.m[12] + m[5]*other.m[13] + m[9]*other.m[14] + m[13]*other.m[15];
    result.m[14] = m[2]*other.m[12] + m[6]*other.m[13] + m[10]*other.m[14] + m[14]*other.m[15];
    result.m[15] = m[3]*other.m[12] + m[7]*other.m[13] + m[11]*other.m[14] + m[15]*other.m[15];
	
    return result;
}


Matrix44 Matrix44::operator *(float f)
{
	Matrix44 result;

	result.m[0] = m[0] * f;
	result.m[1] = m[1] * f;
	result.m[2] = m[2] * f;
	result.m[3] = m[3] * f;

	result.m[4] = m[4] * f;
	result.m[5] = m[5] * f;
	result.m[6] = m[6] * f;
	result.m[7] = m[7] * f;

	result.m[8] = m[8] * f;
	result.m[9] = m[9] * f;
	result.m[10] = m[10] * f;
	result.m[11] = m[11] * f;

	result.m[12] = m[12] * f;
	result.m[13] = m[13] * f;
	result.m[14] = m[14] * f;
	result.m[15] = m[15] * f;

	return result;
}

Matrix44 Matrix44::operator *=(float f)
{
	Matrix44 result;

	result.m[0] = m[0] * f;
	result.m[1] = m[1] * f;
	result.m[2] = m[2] * f;
	result.m[3] = m[3] * f;

	result.m[4] = m[4] * f;
	result.m[5] = m[5] * f;
	result.m[6] = m[6] * f;
	result.m[7] = m[7] * f;

	result.m[8] = m[8] * f;
	result.m[9] = m[9] * f;
	result.m[10] = m[10] * f;
	result.m[11] = m[11] * f;

	result.m[12] = m[12] * f;
	result.m[13] = m[13] * f;
	result.m[14] = m[14] * f;
	result.m[15] = m[15] * f;

	return result;
}


Matrix44* Matrix44::operator +(Matrix44& other)
{
	Matrix44* result = new Matrix44();

	result->m[0] = m[0] + other.m[0];
	result->m[1] = m[1] + other.m[1];
	result->m[2] = m[2] + other.m[2];
	result->m[3] = m[3] + other.m[3];

	result->m[4] = m[4] + other.m[4];
	result->m[5] = m[5] + other.m[5];
	result->m[6] = m[6] + other.m[6];
	result->m[7] = m[7] + other.m[7];

	result->m[8] = m[8] + other.m[8];
	result->m[9] = m[9] + other.m[9];
	result->m[10] = m[10] + other.m[10];
	result->m[11] = m[11] + other.m[11];

	result->m[12] = m[12] + other.m[12];
	result->m[13] = m[13] + other.m[13];
	result->m[14] = m[14] + other.m[14];
	result->m[15] = m[15] + other.m[15];

	return result;
}

Matrix44 Matrix44::operator +=(Matrix44& other)
{
	m[0] += other.m[0];
	m[1] += other.m[1];
	m[2] += other.m[2];
	m[3] += other.m[3];

	m[4] += other.m[4];
	m[5] += other.m[5];
	m[6] += other.m[6];
	m[7] += other.m[7];

	m[8] += other.m[8];
	m[9] += other.m[9];
	m[10] += other.m[10];
	m[11] += other.m[11];

	m[12] += other.m[12];
	m[13] += other.m[13];
	m[14] += other.m[14];
	m[15] += other.m[15];

	return *this;
}

Matrix44 Matrix44::operator -(Matrix44& other)
{
	Matrix44 result;

	result.m[0] = m[0] - other.m[0];
	result.m[1] = m[1] - other.m[1];
	result.m[2] = m[2] - other.m[2];
	result.m[3] = m[3] - other.m[3];

	result.m[4] = m[4] - other.m[4];
	result.m[5] = m[5] - other.m[5];
	result.m[6] = m[6] - other.m[6];
	result.m[7] = m[7] - other.m[7];

	result.m[8] = m[8] - other.m[8];
	result.m[9] = m[9] - other.m[9];
	result.m[10] = m[10] - other.m[10];
	result.m[11] = m[11] - other.m[11];

	result.m[12] = m[12] - other.m[12];
	result.m[13] = m[13] - other.m[13];
	result.m[14] = m[14] - other.m[14];
	result.m[15] = m[15] - other.m[15];

	return result;
}

Matrix44 Matrix44::operator -=(Matrix44& other)
{
	m[0] -= other.m[0];
	m[1] -= other.m[1];
	m[2] -= other.m[2];
	m[3] -= other.m[3];

	m[4] -= other.m[4];
	m[5] -= other.m[5];
	m[6] -= other.m[6];
	m[7] -= other.m[7];

	m[8] -= other.m[8];
	m[9] -= other.m[9];
	m[10] -= other.m[10];
	m[11] -= other.m[11];

	m[12] -= other.m[12];
	m[13] -= other.m[13];
	m[14] -= other.m[14];
	m[15] -= other.m[15];

	return *this;
}

void Matrix44::print(void)
{
	printf("%.2f, %.2f, %.2f, %.2f\n", m[0], m[4], m[8], m[12]);
	printf("%.2f, %.2f, %.2f, %.2f\n", m[1], m[5], m[9], m[13]);
	printf("%.2f, %.2f, %.2f, %.2f\n", m[2], m[6], m[10], m[14]);
	printf("%.2f, %.2f, %.2f, %.2f\n", m[3], m[7], m[11], m[15]);
	printf("\n");
}

