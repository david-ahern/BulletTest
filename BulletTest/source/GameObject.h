#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "stdafx.h"

class Game;
class Camera;

class GameObject
{
private:
	static char* debugClassName;
protected:
	int				OBJECT_TYPE;
	char*			mObjectName;

	Vector3			mPosition;
	Vector3			mRotation;
	// use this for rendering
	Matrix44		mTransform;

	ObjectManager*	mObjectManager;

public:
	GameObject();
	GameObject(char* name, int ObjectType);
	~GameObject();

	int				GetObjectType()					{ return OBJECT_TYPE; }
	char*			GetObjectName()					{ return mObjectName; }
	Vector3			GetPosition()					{ return mPosition; }
	Matrix44		GetTransform()					{ return mTransform; }

	void			SetPosition(Vector3 position)	{ mPosition = position; }
	void			ApplyPosition(Vector3 position) { mPosition += position; }

	void			SetObjectManager(ObjectManager* objManager) { mObjectManager = objManager; }

	virtual void	Create();
	virtual void	Init();
	virtual void	Update(float deltaTime);
	virtual void	Render();
};

#endif