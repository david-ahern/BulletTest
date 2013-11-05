#ifndef _CAMERATHIRDPERSON_H_
#define _CAMERATHIRDPERSON_H_

// Created by: David
// Third person camera that is locked to a target.

#include "stdafx.h"


class CameraThirdPerson : public GameObject
{
private:
	static char* debugClassName;

	GameObject* mTarget;
	Vector3* mTargetPosition;

	Vector3 mRotation;
	float mZoom;

public:
	CameraThirdPerson();
	CameraThirdPerson(char* objectName);
	~CameraThirdPerson();

	void			SetTarget(char* targetName);
	GameObject*		GetTarget()						{ return mTarget; }

	void			SetRotation(Vector3 rotation)	{ mRotation = rotation; }
	void			ApplyRotation(Vector3 rotation) { mRotation += rotation; }

	void			SetZoom(float zoom)				{ mZoom = zoom; }
	void			ApplyZoom(float zoom)			{ mZoom += zoom; }

	void			Create(Vector3 rotation, float zoom);
	void			Init();
	void			Update(float deltaTime);
	void			Render();
};

#endif
