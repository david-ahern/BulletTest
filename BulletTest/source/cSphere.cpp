#include "stdafx.h"

char* cSphere::debugClassName = "cSphere";

cSphere::cSphere()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cSphere::cSphere(char* name) : iCollisionShape(name, CSPHERE_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cSphere::~cSphere()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cSphere::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mRadius = data.nRadius;

	mCollisionShape = new btSphereShape(mRadius);
}

void cSphere::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	glutSolidSphere(mRadius, 10, 10);
}