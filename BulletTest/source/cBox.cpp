#include "stdafx.h"

char* cBox::debugClassName = "cBox";

cBox::cBox()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cBox::cBox(char* name) : iCollisionShape(name, CBOX_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cBox::~cBox()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cBox::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mHalfExtents = data.nHalfExtents;

	mCollisionShape = new btBoxShape(btVector3(mHalfExtents.x,
												mHalfExtents.y,
												mHalfExtents.z));
}

void cBox::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif 

	glPushMatrix();
		glScalef(mHalfExtents.x, mHalfExtents.y, mHalfExtents.z);
		glutSolidCube(2);
	glPopMatrix();
}

