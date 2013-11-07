#include "stdafx.h"

char* cCapsule::debugClassName = "cCapsule";

cCapsule::cCapsule()
{
	debugPrint(debugClassName, "empty constructor");
}

cCapsule::cCapsule(char* name) : iCollisionShape(name, CCAPSULE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cCapsule::~cCapsule()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cCapsule::Create(float radius, float height)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mRadius = radius;
	mHeight = height;

	mCollisionShape = new btCapsuleShape(mRadius, mHeight);
}

void cCapsule::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glPushMatrix();
		glRotatef(90,1,0,0);
		gluCylinder(quad, mRadius, mRadius, mHeight, 10, 10);
		glTranslatef(0, 0, mHeight);
		glutSolidSphere(mRadius, 10, 10);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90,-1,0,0);
		gluCylinder(quad, mRadius, mRadius, mHeight, 10, 10);
		glTranslatef(0, 0, mHeight);
		glutSolidSphere(mRadius, 10, 10);
	glPopMatrix();
}

