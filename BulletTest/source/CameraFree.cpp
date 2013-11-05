#include "stdafx.h"

char* CameraFree::debugClassName = "CameraFree";

CameraFree::CameraFree()
{
	debugPrint(debugClassName, "empty constructor");
}

CameraFree::CameraFree(char* name) : GameObject(name, CAMERAFREE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

CameraFree::~CameraFree()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}

void CameraFree::ApplyRotation(Vector3 rotation)
{
	mRotation += rotation;

	if (mRotation.x > 180)
		mRotation.x -= 360;
	if (mRotation.x < -180)
		mRotation.x += 360;

	if (mRotation.y > 180)
		mRotation.y -= 360;
	if (mRotation.y < -180)
		mRotation.y += 360;
}

void CameraFree::Create(Vector3 position, Vector3 rotation, float movementSpeed, float rotationSpeed)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mPosition = position;
	mRotation = rotation;
	mMovementSpeed = movementSpeed;
	mRotationSpeed = rotationSpeed;
}

void CameraFree::Init()
{
	debugPrint(debugClassName, mObjectName, "Init");
}

void CameraFree::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");
}

void CameraFree::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glRotatef(mRotation.x, 1.0, 0.0, 0.0);
	glRotatef(mRotation.y, 0.0, 1.0, 0.0);

	glTranslatef(-mPosition.x, -mPosition.y, -mPosition.z);
}

