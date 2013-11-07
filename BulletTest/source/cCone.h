#ifndef _CCONE_H_
#define _CCONE_H_

// Created by: David
// Class used to render a cone and hods the cone collision shape

#include "stdafx.h"


class cCone : public iCollisionShape
{
private:
	static char* debugClassName;

	float				mRadius;
	float				mHeight;

public:
	cCone();
	cCone(char* objectName);
	~cCone();

	void Create(float radius, float height);
	void Render();
};

#endif
