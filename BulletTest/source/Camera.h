#ifndef _Camera_H_
#define _Camera_H_

// Created by: David
// Camera to move freely around the world

#include "stdafx.h"

#define FREE_CAMERA 0
#define FIRSTPERSON_CAMERA 1
#define THIRDPERSON_CAMERA 2

class Camera : public GameObject
{
private:
	static char* debugClassName;

	Vector3		mRotation;
	float		mMovementSpeed;
	float		mRotationSpeed;

	int			mCameraMode;

	float		zoom;
	GameObject* mTarget;
	
public:
	Camera();
	Camera(char* objectName);
	~Camera();

	void		SetCameraMode(int mode)			{ mCameraMode = mode; }
	int			GetCameraMode()					{ return mCameraMode; }

	Vector3		GetRotation()					{ return mRotation; }
	float		GetMovementSpeed()				{ return mMovementSpeed; }
	float		GetRotationSpeed()				{ return mRotationSpeed; }

	void		SetRotation(Vector3 rotation)	{ mRotation = rotation; }
	void		SetMovementSpeed(float speed)	{ mMovementSpeed = speed; }
	void		SetRotationSpeed(float speed)	{ mRotationSpeed = speed; }

	void		SetTarget(GameObject* target)	{ mTarget = target; }

	void		ApplyRotation(Vector3 rotation);

	void		Create(Vector3 position, Vector3 rotation, float movementSpeed, float rotationSpeed);
	void		Update(float deltaTime);
	void		Render();
};

#endif
