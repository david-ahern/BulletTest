#include "stdafx.h"

char* cPlayerCube::debugClassName = "cPlayerCube";

cPlayerCube::cPlayerCube()
{
	debugPrint(debugClassName, "empty constructor");
}

cPlayerCube::cPlayerCube(char* name) : GameObject(name, CPLAYERCUBE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cPlayerCube::~cPlayerCube()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cPlayerCube::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");
}

void cPlayerCube::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");
}

void cPlayerCube::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");
}

