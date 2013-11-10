#ifndef _CCYLINDER_H_
#define _CCYLINDER_H_

// Created by: David
// Class used to render a cylinder, and holds the cylinder collision shape

#include "stdafx.h"


class cCylinder : public iCollisionShape
{
private:
	static char* debugClassName;

	Vector3				mHalfExtents;

public:
	cCylinder();
	cCylinder(char* objectName);
	~cCylinder();

	void Create(ObjectData data);
	void RenderShape();
};

#endif
