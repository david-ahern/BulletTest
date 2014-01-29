#include "stdafx.h"

char* GameObject::debugClassName = "GameObject";

GameObject::GameObject()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, " empty base constructor");
#endif

	OBJECT_TYPE = NO_OBJECT_TYPE;
}

GameObject::GameObject(char* name, int ObjectType)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, name, "base constructor");
#endif

	mObjectName = name;

	OBJECT_TYPE = ObjectType;
}

GameObject::~GameObject()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "base destructor");
#endif

	delete mObjectName;
}

void GameObject::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "default Create");
#endif
}

void GameObject::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "default Init");
#endif
}

void GameObject::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "default Update");
#endif
}

void GameObject::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, " default Render");
#endif
}
