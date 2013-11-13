#ifndef _CPLAYER_H_
#define _CPLAYER_H_

// Created by: David
// Cube controlled by player,

#include "stdafx.h"


class cPlayer : public GameObject
{
private:
	static char* debugClassName;
	
	cRigidBody*		mRigidBody;

public:
	cPlayer();
	cPlayer(char* objectName);
	~cPlayer();

	cRigidBody*		GetRigidBody()	{ return mRigidBody; }

	void Create(ObjectData data);
	void Update(float deltaTime);
	void Render();
};

#endif
