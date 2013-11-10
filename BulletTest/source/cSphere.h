#ifndef _CBALL_H_
#define _CBALL_H_

// Created by: David
// Class used to render a ball, and holds the bullet collision shape

#include "stdafx.h"


class cSphere : public iCollisionShape
{
private:
	static char* debugClassName;

	float				mRadius;
	
public:
	cSphere();
	cSphere(char* objectName);
	~cSphere();

	void Create(ObjectData data);
	void RenderShape();
};

#endif
