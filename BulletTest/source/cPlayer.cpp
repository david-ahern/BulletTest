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

	mMovementDirection[MOVE_FORWARD] = false;
	mMovementDirection[MOVE_BACKWARD] = false;
	mMovementDirection[MOVE_LEFT] = false;
	mMovementDirection[MOVE_RIGHT] = false;
}

void cPlayer::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");

	float xrotrad = mRotation.x * DEG_TO_RAD;
	float yrotrad = mRotation.y * DEG_TO_RAD;

	float curTime = mMovementTimer->GetTime();

	if(curTime - mPrevMovementTime > mMovementStep)
	{
		if(mMovementDirection[MOVE_FORWARD])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(sin(yrotrad) * mMovementForce, 0, -cos(yrotrad) * mMovementForce));
		}
		if(mMovementDirection[MOVE_BACKWARD])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(-sin(yrotrad) * mMovementForce, 0, cos(yrotrad) * mMovementForce));
		}
		if(mMovementDirection[MOVE_LEFT])
		{
			mRigidBody->SetActive(true);
			mRigidBody->ApplyForce(Vector3(cos(yrotrad) * mMovementForce, 0, sin(yrotrad) * mMovementForce));
		}
		if(mMovementDirection[MOVE_RIGHT])
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

