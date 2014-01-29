#include "stdafx.h"

char* iCollisionShape::debugClassName = "iCollisionShape";

GLUquadricObj* iCollisionShape::quad = gluNewQuadric();

iCollisionShape::iCollisionShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

iCollisionShape::iCollisionShape(char* name, int objectType) : GameObject(name, objectType)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

iCollisionShape::~iCollisionShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	delete quad;
	delete mCollisionShape;
}

void iCollisionShape::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "base Create");
#endif
}

void iCollisionShape::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "base RenderMe");
#endif
}

