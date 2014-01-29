#include "stdafx.h"

char* BulletWorld::debugClassName = "BulletWorld";

BulletWorld::BulletWorld()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

BulletWorld::BulletWorld(char* name) : GameObject(name, BULLETWORLD_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

BulletWorld::~BulletWorld()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	mBtWorld->~btDynamicsWorld();
}

void BulletWorld::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);
#endif

	mGravity = data.nGravity;

	btDefaultCollisionConfiguration* collisionConfig = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfig);
	btDbvtBroadphase* broadphase = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();

	mBtWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

	mLock2D = false;

	SetGravity(btVector3(mGravity.x, mGravity.y, mGravity.z));

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create", END);
#endif
}

void BulletWorld::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);
#endif

	mBtWorld->stepSimulation(deltaTime);

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", END);
#endif
}

void BulletWorld::SetGravity(btVector3& newGravity)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetGravity");
#endif

	mBtWorld->setGravity(newGravity);
}

btVector3 BulletWorld::GetGravity()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "GetGravity");
#endif

	return mBtWorld->getGravity();
}