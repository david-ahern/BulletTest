#include "stdafx.h"

char* cBox::debugClassName = "cBox";

cBox::cBox()
{
	debugPrint(debugClassName, "empty constructor");
}

cBox::cBox(char* name) : iCollisionShape(name, CBOX_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cBox::~cBox()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cBox::Create(Vector3 halfExtents)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mCollisionShape = new btBoxShape(btVector3(halfExtents.x,
												halfExtents.y,
												halfExtents.z));

	mHalfExtents = ((btBoxShape*)mCollisionShape)->getHalfExtentsWithMargin();
}

void cBox::RenderShape()
{
	debugPrint(debugClassName, mObjectName, "Render");
	glPushMatrix();
		glScalef(mHalfExtents.x, mHalfExtents.y, mHalfExtents.z);
		glutSolidCube(2);
	glPopMatrix();
}

