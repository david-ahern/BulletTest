#ifndef _ICOLLISIONSHAPE_H_
#define _ICOLLISIONSHAPE_H_

// Created by: David
// Virtual class which stores a collision shape, and the various shapes inherit
// from this class

#include "stdafx.h"

class GameObject;

class iCollisionShape : public GameObject
{
protected:
	static char* debugClassName;

	btCollisionShape*	mCollisionShape;

public:
	iCollisionShape();
	iCollisionShape(char* objectName, int objectType);
	~iCollisionShape();

	btCollisionShape*	GetCollisionShape() { return mCollisionShape; }

	void Create();
	void Render();
};

#endif