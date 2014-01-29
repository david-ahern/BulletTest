#include "stdafx.h"

char* cRigidBody::debugClassName = "cRigidBody";

cRigidBody::cRigidBody()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cRigidBody::cRigidBody(char* name) : GameObject(name, CRIGIDBODY_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cRigidBody::~cRigidBody()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	delete mRigidBody;
}

void cRigidBody::SetFriction(float friction)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetFriction");
#endif

	mRigidBody->setFriction(friction);
	mRigidBody->setRollingFriction(friction);
}

void cRigidBody::SetRestitution(float restitution)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetRestitution");
#endif

	mRigidBody->setRestitution(restitution);
}

void cRigidBody::SetPosition(Vector3 position)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetRestitution");
#endif

	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(position.x, position.y, position.z));

	mRigidBody->setCenterOfMassTransform(trans);
}

void cRigidBody::SetRotation(Vector3 rotation)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetRotation");
#endif

	btTransform trans;
	trans.setIdentity();
	trans.setRotation(btQuaternion(rotation.x * DEG_TO_RAD, rotation.y * DEG_TO_RAD, rotation.z * DEG_TO_RAD));

	mRigidBody->setWorldTransform(trans);
}

void cRigidBody::SetVelocity(Vector3 velocity)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetVelocity");
#endif

	mRigidBody->setLinearVelocity(btVector3(velocity.x, velocity.y, velocity.z));
}

void cRigidBody::ApplyForce(Vector3 force)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "ApplyForce");
#endif

	mRigidBody->applyCentralForce(btVector3(force.x, force.y, force.z));
}

void cRigidBody::SetActive(bool active)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetActive");
#endif

	mRigidBody->setActivationState(active);
}

void cRigidBody::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mBulletWorld = ((BulletWorld*)mObjectManager->GetGameObject(BULLETWORLD_OBJECT))->GetWorld();

	mCollisionShapeObject = (iCollisionShape*)mObjectManager->GetGameObject(data.nCollisionShapeName);

	mCollisionShape = mCollisionShapeObject->GetCollisionShape();

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(data.nPosition.x, data.nPosition.y, data.nPosition.z));
	startTransform.setRotation(btQuaternion(data.nRotation.x * DEG_TO_RAD, data.nRotation.y * DEG_TO_RAD, data.nRotation.z * DEG_TO_RAD));

	btVector3 inertia(0,0,0);
	if (data.nMass != 0)
		mCollisionShape->calculateLocalInertia(data.nMass, inertia);

	btMotionState* motion = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo info(data.nMass, motion, mCollisionShape, inertia);
	mRigidBody = new btRigidBody(info);

	mBulletWorld->addRigidBody(mRigidBody);

	mRigidBody->setFriction(data.nFriction);
	mRigidBody->setRollingFriction(data.nRollingFriction);

	mRigidBody->setRestitution(data.nRestitution);
}

void cRigidBody::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update");
#endif

	btTransform trans;
	mRigidBody->getMotionState()->getWorldTransform(trans);
	trans.getOpenGLMatrix(mTransform.getMatrix());

	btVector3 pos = mRigidBody->getCenterOfMassPosition();
	mPosition = Vector3(pos.x(), pos.y(), pos.z());

	btQuaternion rot = mRigidBody->getOrientation();
}

void cRigidBody::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	GLfloat c[] = { 1, 1, 1, 0 };
	glMaterialfv (GL_FRONT, GL_AMBIENT, c);

	GLUquadricObj* quad = gluNewQuadric();

	glPushMatrix();

		glMultMatrixf(mTransform.getMatrix());

		mCollisionShapeObject->RenderShape();

	glPopMatrix();
}