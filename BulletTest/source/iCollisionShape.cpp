#include "stdafx.h"

char* iCollisionShape::debugClassName = "iCollisionShape";

GLUquadricObj* iCollisionShape::quad = gluNewQuadric();

iCollisionShape::iCollisionShape()
{
	debugPrint(debugClassName, "empty constructor");
}

iCollisionShape::iCollisionShape(char* name, int objectType) : GameObject(name, objectType)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

iCollisionShape::~iCollisionShape()
{
	debugPrint(debugClassName, mObjectName, "destructor");

	delete quad;
	delete mCollisionShape;
}

void iCollisionShape::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "base Create");
}

void iCollisionShape::RenderShape()
{
	debugPrint(debugClassName, mObjectName, "base RenderMe");
}

