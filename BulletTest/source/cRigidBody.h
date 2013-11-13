#ifndef _CRIGIDBODY_H_
#define _CRIGIDBODY_H_

// Created by: David
// Class used to create, update and call the render function of the collision shape of a rigid body

#include "stdafx.h"


class cRigidBody : public GameObject
{
private:
	static char* debugClassName;

	btRigidBody*		mRigidBody;
	
	btDynamicsWorld*	mBulletWorld;
	
	iCollisionShape*	mCollisionShapeObject;

	btCollisionShape*	mCollisionShape;
protected:


public:
	cRigidBody();
	cRigidBody(char* objectName);
	~cRigidBody();

	btRigidBody*	GetRigidBody() { return mRigidBody; }

	void	SetFriction(float friction);
	void	SetRestitution(float restitution);
	void	SetPosition(Vector3 position);
	void	SetRotation(Vector3 rotation);
	void	SetVelocity(Vector3 velocity);
	void	ApplyForce(Vector3 force);
	void	SetActive(bool active);
	void	SetGravity(Vector3 gravity);

	void	Create(ObjectData data);
	void	Update(float deltaTime);
	void	Render();
};

#endif
