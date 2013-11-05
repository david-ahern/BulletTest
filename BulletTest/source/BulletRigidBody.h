#ifndef _BULLETRIGIDBODY_H_
#define _BULLETRIGIDBODY_H_

#include "stdafx.h"

class GameObject;
class BulletWorld;
class BulletCollisionShape;

class BulletRigidBody : public GameObject
{
private:
	static char* debugClassName;

	btRigidBody*		mBody;

	btCollisionShape*	mShape;
	btDynamicsWorld*	mBtWorld;

public:
	BulletRigidBody();
	BulletRigidBody(char* objectName);
	~BulletRigidBody();

	void	Create(char* collisionShapeName, Vector3 position, float mass);
	void	Update(float deltaTime);
	void	Render();

	void	SetFriction(float friction);
	void	SetRestitution(float restitution);
	void	SetPosition(btVector3& position);
	void	SetVelocity(btVector3& velocity);
	void	ApplyForce(btVector3& force);
};

#endif