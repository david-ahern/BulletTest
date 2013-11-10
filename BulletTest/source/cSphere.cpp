#include "stdafx.h"

char* cSphere::debugClassName = "cSphere";

cSphere::cSphere()
{
	debugPrint(debugClassName, "empty constructor");
}

cSphere::cSphere(char* name) : iCollisionShape(name, CSPHERE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cSphere::~cSphere()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cSphere::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mRadius = data.nRadius;

	mCollisionShape = new btSphereShape(mRadius);
}

void cSphere::RenderShape()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glutSolidSphere(mRadius, 10, 10);
}