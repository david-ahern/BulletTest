#ifndef _CPLAYERCUBE_H_
#define _CPLAYERCUBE_H_

// Created by: David
// Cube controlled by player,

#include "stdafx.h"


class cPlayerCube : public GameObject
{
private:
	static char* debugClassName;
	
	cRigidBody*		mRigidBody;

public:
	cPlayerCube();
	cPlayerCube(char* objectName);
	~cPlayerCube();


	void Create(ObjectData data);
	void Update(float deltaTime);
	void Render();
};

#endif
