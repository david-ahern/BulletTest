#include "stdafx.h"

char* Camera::debugClassName = "Camera";

Camera::Camera()
{
	debugPrint(debugClassName, "empty constructor");
}

Camera::Camera(char* name) : GameObject(name, CAMERA_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

Camera::~Camera()
{
	debugPrint(debugClassName, mObjectName, "destructor");

	delete mTarget;
}

void Camera::ApplyRotation(Vector3 rotation)
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

void Camera::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mPosition = data.nPosition;
	mRotation = data.nRotation;
	mMovementSpeed = data.nMovementSpeed;
	mRotationSpeed = data.nRotationSpeed;

	zoom = 10;

	mCameraMode = FREE_CAMERA;
}

void Camera::Update(float deltaTime)
{
	if (mCameraMode == FREE_CAMERA || mCameraMode == FIRSTPERSON_CAMERA)
		return;

	debugPrint(debugClassName, mObjectName, "Update");

	mPosition = mTarget->GetPosition();

}

void Camera::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	if (mCameraMode == THIRDPERSON_CAMERA)
		glTranslatef(0, 0, -zoom);

	glRotatef(mRotation.x, 1.0, 0.0, 0.0);
	glRotatef(mRotation.y, 0.0, 1.0, 0.0);

	glTranslatef(-mPosition.x, -mPosition.y, -mPosition.z);
}

