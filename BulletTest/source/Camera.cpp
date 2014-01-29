#include "stdafx.h"

char* Camera::debugClassName = "Camera";

Camera::Camera()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

Camera::Camera(char* name) : GameObject(name, CAMERA_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

Camera::~Camera()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	delete mTarget;
}

void Camera::ApplyRotation(Vector3 rotation)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "ApplyRotation");
#endif

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
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

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

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update");
#endif

	mPosition = mTarget->GetPosition();

}

void Camera::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	if (mCameraMode == THIRDPERSON_CAMERA)
		glTranslatef(0, 0, -zoom);

	glRotatef(mRotation.x, 1.0, 0.0, 0.0);
	glRotatef(mRotation.y, 0.0, 1.0, 0.0);

	glTranslatef(-mPosition.x, -mPosition.y, -mPosition.z);
}

