#include "stdafx.h"

char* CameraThirdPerson::debugClassName = "CameraThirdPerson";

CameraThirdPerson::CameraThirdPerson()
{
	debugPrint(debugClassName, "empty constructor");
}

CameraThirdPerson::CameraThirdPerson(char* name) : GameObject(name, CAMERATHIRDPERSON_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

CameraThirdPerson::~CameraThirdPerson()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void CameraThirdPerson::SetTarget(char* targetName)
{
	debugPrint(debugClassName, mObjectName, "SetTarget");

	mTarget = mObjectManager->GetGameObject(targetName);
	mTargetPosition = &mTarget->GetPosition();
}

void CameraThirdPerson::Create(Vector3 rotation, float zoom)
{
	debugPrint(debugClassName, mObjectName, "Create");

	SetRotation(rotation);
	SetZoom(zoom);
}

void CameraThirdPerson::Init()
{
	debugPrint(debugClassName, mObjectName, "Init");

	// get pointer to targets position
	mTargetPosition = &mTarget->GetPosition();
}

void CameraThirdPerson::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");

	mPosition = *mTargetPosition;
}

void CameraThirdPerson::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	// apply the zoom
	glTranslatef(0.0, 0.0, mZoom);
	// rotate around the x axis
	glRotatef(mRotation.x, 1.0, 0.0, 0.0);
	// rotate around the y axis
	glRotatef(mRotation.y, 0.0, 1.0, 0.0);

	// translate the screen position to the camera
	glTranslatef(mPosition.x, mPosition.y, mPosition.z);
}

