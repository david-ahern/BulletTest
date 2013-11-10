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


void cBox::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mHalfExtents = data.nHalfExtents;

	mCollisionShape = new btBoxShape(btVector3(mHalfExtents.x,
												mHalfExtents.y,
												mHalfExtents.z));
}

void cBox::RenderShape()
{
	debugPrint(debugClassName, mObjectName, "Render");
	glPushMatrix();
		glScalef(mHalfExtents.x, mHalfExtents.y, mHalfExtents.z);
		glutSolidCube(2);
	glPopMatrix();
}

