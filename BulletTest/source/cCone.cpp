#include "stdafx.h"

char* cCone::debugClassName = "cCone";

cCone::cCone()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cCone::cCone(char* name) : iCollisionShape(name, CCONE_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cCone::~cCone()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cCone::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mRadius = data.nRadius;
	mHeight = data.nHeight;

	mCollisionShape = new btConeShape(mRadius, mHeight);
}

void cCone::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(quad, mRadius/2, mRadius, mHeight/2, 10, 5);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, -1, 0, 0);
		gluCylinder(quad, mRadius/2, 0, mHeight/2, 10, 5);
	glPopMatrix();
}

