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

	void	SetFriction(float friction);
	void	SetRestitution(float restitution);
	void	SetPosition(btVector3& position);
	void	SetVelocity(btVector3& velocity);
	void	ApplyForce(btVector3& force);

	void Create(char* collisionShapeName, Vector3 position, 
					Vector3 rotation, float mass);
	void Update(float deltaTime);
	void Render();
};

#endif
