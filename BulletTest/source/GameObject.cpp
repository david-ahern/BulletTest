#include "stdafx.h"

char* GameObject::debugClassName = "GameObject";

GameObject::GameObject()
{
	debugPrint(debugClassName, " empty base constructor");

	OBJECT_TYPE = NO_OBJECT_TYPE;
}

GameObject::GameObject(char* name, int ObjectType)
{
	debugPrint(debugClassName, name, "base constructor");

	mObjectName = name;

	OBJECT_TYPE = ObjectType;
}

GameObject::~GameObject()
{
	debugPrint(debugClassName, mObjectName, "base destructor");
}

void GameObject::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "default Create");
}

void GameObject::Init()
{
	debugPrint(debugClassName, mObjectName, "default Init");
}

void GameObject::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "default Update");
}

void GameObject::Render()
{
	debugPrint(debugClassName, mObjectName, " default Render");
}
