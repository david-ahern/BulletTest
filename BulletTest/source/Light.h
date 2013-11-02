#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "stdafx.h"

class GameObject;

class Light: public GameObject
{
private:
	static char* debugClassName;

	Vector4		mAmbient;
	Vector4		mDiffuse;
	Vector4		mSpecular;

public:
	Light();
	Light(char* objectName);
	~Light();

	void	Create( Vector3 position, Vector4 ambient, Vector4 diffuse, Vector4 specular);
};

#endif