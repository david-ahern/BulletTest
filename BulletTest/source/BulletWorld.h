#ifndef _BULLETWORLD_H_
#define _BULLETWORLD_H_

#include "stdafx.h"

class GameObject;
class Timer;

class BulletWorld : public GameObject
{
private:
	static char* debugClassName;

	btDynamicsWorld*	mBtWorld;
	
	bool				mLock2D;

	Vector3				mGravity;

public:
	BulletWorld();
	BulletWorld(char* objectName);
	~BulletWorld();

	void				Create(Vector3 gravity);

	btDynamicsWorld*	GetWorld()		{ return mBtWorld; }

	void				SetGravity(btVector3& newGravity);
	btVector3			GetGravity();

	void				Update(float deltaTime);
};

#endif