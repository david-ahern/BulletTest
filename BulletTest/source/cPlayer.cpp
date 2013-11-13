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
}

void cPlayer::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");

	mPosition = mRigidBody->GetPosition();
}

void cPlayer::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");
}

