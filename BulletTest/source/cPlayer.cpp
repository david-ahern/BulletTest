#include "stdafx.h"

char* cPlayer::debugClassName = "cPlayer";

cPlayer::cPlayer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cPlayer::cPlayer(char* name) : GameObject(name, CPLAYER_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cPlayer::~cPlayer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	delete mRigidBody;
}


void cPlayer::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mRigidBody = (cRigidBody*)mObjectManager->GetGameObject(data.nRigidBodyName);

	mPosition = mRigidBody->GetPosition();

	mMovementTimer = new Timer("cPlayerMovementTimer");
	mMovementTimer->Init();
	mPrevMovementTime = mMovementTimer->GetTime();
	mMovementForce = 100;
}

void cPlayer::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update");
#endif

	float xrotrad = mRotation.x * DEG_TO_RAD;
	float yrotrad = mRotation.y * DEG_TO_RAD;

	float curTime = mMovementTimer->GetTime();

	mPosition = mRigidBody->GetPosition();
}

void cPlayer::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif
}

