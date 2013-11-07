#ifndef _CCAPSULE_H_
#define _CCAPSULE_H_

// Created by: David
// Class used to render a capusle and holds the capsule collision shape

#include "stdafx.h"


class cCapsule : public iCollisionShape
{
private:
	static char* debugClassName;

	float				mRadius;
	float				mHeight;

public:
	cCapsule();
	cCapsule(char* objectName);
	~cCapsule();

	void Create(float radius, float height);
	void Render();
};

#endif
