#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "stdafx.h"

class GameObject;

class Light: public GameObject
{
private:
	static char*	debugClassName;
	static int		sNumberOfLights;

	Vector4		mAmbient;
	Vector4		mDiffuse;
	Vector4		mSpecular;

	int			mLightNum;

public:
	Light();
	Light(char* objectName);
	~Light();

	void	Create(ObjectData data);
};

#endif