#include "stdafx.h"

char* cCylinder::debugClassName = "cCylinder";

cCylinder::cCylinder()
{
	debugPrint(debugClassName, "empty constructor");
}

cCylinder::cCylinder(char* name) : iCollisionShape(name, CCYLINDER_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cCylinder::~cCylinder()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cCylinder::Create(Vector3 halfExtents)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mHalfExtents = halfExtents;

	mCollisionShape = new btCylinderShape(btVector3(mHalfExtents.x,
													mHalfExtents.y,
													mHalfExtents.z));
}

void cCylinder::RenderShape()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(quad, mHalfExtents.x, mHalfExtents.y, mHalfExtents.z, 10, 10);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, -1, 0, 0);
		gluCylinder(quad, mHalfExtents.x, mHalfExtents.y, mHalfExtents.z, 10, 10);
	glPopMatrix();
}

