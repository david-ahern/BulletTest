#include "stdafx.h"

char* cPlayer::debugClassName = "cPlayer";

cPlayer::cPlayer()
{
	debugPrint(debugClassName, "empty constructor");
}

cPlayer::cPlayer(char* name) : GameObject(name, CPLAYER_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cPlayer::~cPlayer()
{
	debugPrint(debugClassName, mObjectName, "destructor");
	delete mRigidBody;
}


void cPlayer::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mRigidBody = (cRigidBody*)mObjectManager->GetGameObject(data.nRigidBodyName);

	mPosition = mRigidBody->GetPosition();

	mMovementTimer = new Timer("cPlayerMovementTimer");
	mMovementTimer->Init();
	mPrevMovementTime = mMovementTimer->GetTime();
	mMovementForce = 100;

	mMovementDirections[MOVE_FORWARD] = false;
	mMovementDirections[MOVE_BACKWARD] = false;
	mMovementDirections[MOVE_LEFT] = false;
	mMovementDirections[MOVE_RIGHT] = false;
}

void cPlayer::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");

	float xrotrad = mRotation.x * DEG_TO_RAD;
	float yrotrad = mRotation.y * DEG_TO_RAD;

	float curTime = mMovementTimer->GetTime();

	if(1)
	{
		if()
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(sin(yrotrad) * mMovementForce, 0, -cos(yrotrad) * mMovementForce));
		}
		if(mMovementDirections[MOVE_BACKWARD])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(-sin(yrotrad) * mMovementForce, 0, cos(yrotrad) * mMovementForce));
		}
		if(mMovementDirections[MOVE_LEFT])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(cos(yrotrad) * mMovementForce, 0, sin(yrotrad) * mMovementForce));
		}
		if(mMovementDirections[MOVE_RIGHT])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(-cos(yrotrad) * mMovementForce, 0, -sin(yrotrad) * mMovementForce));
		}
		mPrevMovementTime = curTime;
	}

	mPosition = mRigidBody->GetPosition();
}

void cPlayer::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");
}

