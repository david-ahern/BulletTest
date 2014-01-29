#include "stdafx.h"

char* cCylinder::debugClassName = "cCylinder";

cCylinder::cCylinder()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cCylinder::cCylinder(char* name) : iCollisionShape(name, CCYLINDER_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cCylinder::~cCylinder()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cCylinder::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mHalfExtents = data.nHalfExtents;

	mCollisionShape = new btCylinderShape(btVector3(mHalfExtents.x,
													mHalfExtents.y,
													mHalfExtents.z));
}

void cCylinder::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(quad, mHalfExtents.x, mHalfExtents.y, mHalfExtents.z, 10, 10);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, -1, 0, 0);
		gluCylinder(quad, mHalfExtents.x, mHalfExtents.y, mHalfExtents.z, 10, 10);
	glPopMatrix();
}

