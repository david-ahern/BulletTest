#ifndef _CPLAYER_H_
#define _CPLAYER_H_

// Created by: David
// Cube controlled by player,

#include "stdafx.h"

// movement codes
#define MOVE_FORWARD	0
#define MOVE_BACKWARD	1
#define MOVE_LEFT		2
#define MOVE_RIGHT		3
// spin codes
#define SPIN_LEFT		0
#define SPIN_RIGHT		1

class cPlayer : public GameObject
{
private:
	static char* debugClassName;
	
	cRigidBody*		mRigidBody;

	bool			mMovementDirections[4];
	bool			mSpinDirection[2];

	Timer*			mMovementTimer;
	float			mPrevMovementTime;
	float			mMovementSpeed;
	float			mMovementForce;
public:
	cPlayer();
	cPlayer(char* objectName);
	~cPlayer();

	cRigidBody*		GetRigidBody()				{ return mRigidBody; }

	void			EnableMovement(int code)	{ mMovementDirections[code] = true; }
	void			DisableMovement(int code)	{ mMovementDirections[code] = false; }
	void			EnableSpin(int code)		{ mSpinDirection[code] = true; }
	void			DisableSpin(int code)		{ mSpinDirection[code] = false; }

	void Create(ObjectData data);
	void Update(float deltaTime);
	void Render();
};

#endif
