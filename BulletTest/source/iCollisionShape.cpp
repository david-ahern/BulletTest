#include "stdafx.h"

char* iCollisionShape::debugClassName = "iCollisionShape";

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
}

void iCollisionShape::Create()
{
	debugPrint(debugClassName, mObjectName, "base Create");
}

void iCollisionShape::Render()
{
	debugPrint(debugClassName, mObjectName, "base Render");
}

