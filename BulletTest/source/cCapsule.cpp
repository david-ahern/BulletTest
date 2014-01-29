#include "stdafx.h"

char* cCapsule::debugClassName = "cCapsule";

cCapsule::cCapsule()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cCapsule::cCapsule(char* name) : iCollisionShape(name, CCAPSULE_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cCapsule::~cCapsule()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cCapsule::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mRadius = data.nRadius;
	mHeight = data.nHeight;

	mCollisionShape = new btCapsuleShape(mRadius, mHeight);
}

void cCapsule::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	glPushMatrix();
		glRotatef(90,1,0,0);
		gluCylinder(quad, mRadius, mRadius, mHeight/2, 10, 10);
		glTranslatef(0, 0, mHeight/2);
		glutSolidSphere(mRadius, 10, 10);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90,-1,0,0);
		gluCylinder(quad, mRadius, mRadius, mHeight/2, 10, 10);
		glTranslatef(0, 0, mHeight/2);
		glutSolidSphere(mRadius, 10, 10);
	glPopMatrix();
}

