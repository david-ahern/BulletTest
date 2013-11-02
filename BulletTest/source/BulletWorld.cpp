#include "stdafx.h"

char* BulletWorld::debugClassName = "BulletWorld";

BulletWorld::BulletWorld()
{
	debugPrint(debugClassName, "empty constructor");
}

BulletWorld::BulletWorld(char* name) : GameObject(name, BULLETWORLD_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

BulletWorld::~BulletWorld()
{
	debugPrint(debugClassName, mObjectName, "destructor");
	mBtWorld->~btDynamicsWorld();
}

void BulletWorld::Create(Vector3 _gravity)
{
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);

	mGravity = _gravity;

	btDefaultCollisionConfiguration* collisionConfig = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfig);
	btDbvtBroadphase* broadphase = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();

	mBtWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

	mLock2D = false;

	SetGravity(btVector3(mGravity.x, mGravity.y, mGravity.z));

	debugPrint(debugClassName, mObjectName, "Create", END);
}

void BulletWorld::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);

	mBtWorld->stepSimulation(deltaTime);

	debugPrint(debugClassName, mObjectName, "Update", END);
}

void BulletWorld::SetGravity(btVector3& newGravity)
{
	debugPrint(debugClassName, mObjectName, "SetGravity");

	mBtWorld->setGravity(newGravity);
}

btVector3 BulletWorld::GetGravity()
{
	debugPrint(debugClassName, mObjectName, "GetGravity");

	return mBtWorld->getGravity();
}