#ifndef _CBOX_H_
#define _CBOX_H_

// Created by: David
// Class used to render a box, and holds the bullet collision shape

#include "stdafx.h"


class cBox : public iCollisionShape
{
private:
	static char* debugClassName;

	Vector3				mHalfExtents;

public:
	cBox();
	cBox(char* objectName);
	~cBox();

	void Create(Vector3 halfExtents);
	void RenderShape();
};

#endif
