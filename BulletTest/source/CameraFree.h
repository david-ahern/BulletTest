#ifndef _CAMERAFREE_H_
#define _CAMERAFREE_H_

// Created by: David
// Camera to move freely around the world

#include "stdafx.h"


class CameraFree : public GameObject
{
private:
	static char* debugClassName;

	Vector3 mRotation;
	float mMovementSpeed;
	float mRotationSpeed;

protected:


public:
	CameraFree();
	CameraFree(char* objectName);
	~CameraFree();

	Vector3		GetRotation()					{ return mRotation; }
	float		GetMovementSpeed()				{ return mMovementSpeed; }
	float		GetRotationSpeed()				{ return mRotationSpeed; }

	void		SetRotation(Vector3 rotation)	{ mRotation = rotation; }
	void		SetMovementSpeed(float speed)	{ mMovementSpeed = speed; }
	void		SetRotationSpeed(float speed)	{ mRotationSpeed = speed; }

	void		ApplyRotation(Vector3 rotation);

	void		Create(Vector3 position, Vector3 rotation, float movementSpeed, float rotationSpeed);
	void		Render();
};

#endif
