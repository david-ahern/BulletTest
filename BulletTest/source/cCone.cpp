#include "stdafx.h"

char* cCone::debugClassName = "cCone";

cCone::cCone()
{
	debugPrint(debugClassName, "empty constructor");
}

cCone::cCone(char* name) : iCollisionShape(name, CCONE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cCone::~cCone()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cCone::Create(float radius, float height)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mRadius = radius;
	mHeight = height;

	mCollisionShape = new btConeShape(mRadius, mHeight);
}

void cCone::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(quad, mRadius/2, mRadius, mHeight/2, 10, 5);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, -1, 0, 0);
		gluCylinder(quad, mRadius/2, 0, mHeight/2, 10, 5);
	glPopMatrix();
}

