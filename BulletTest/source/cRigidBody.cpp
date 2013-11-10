#include "stdafx.h"

char* cRigidBody::debugClassName = "cRigidBody";

cRigidBody::cRigidBody()
{
	debugPrint(debugClassName, "empty constructor");
}

cRigidBody::cRigidBody(char* name) : GameObject(name, CRIGIDBODY_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cRigidBody::~cRigidBody()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}

void cRigidBody::SetFriction(float friction)
{
	mRigidBody->setFriction(friction);
	mRigidBody->setRollingFriction(friction);
}

void cRigidBody::SetRestitution(float restitution)
{
	mRigidBody->setRestitution(restitution);
}

void cRigidBody::SetPosition(Vector3 position)
{
	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(position.x, position.y, position.z));

	mRigidBody->setCenterOfMassTransform(trans);
}

void cRigidBody::SetRotation(Vector3 rotation)
{
	btTransform trans;
	trans.setIdentity();
	trans.setRotation(btQuaternion(rotation.x * DEG_TO_RAD, rotation.y * DEG_TO_RAD, rotation.z * DEG_TO_RAD));

	mRigidBody->setWorldTransform(trans);
}

void cRigidBody::SetVelocity(Vector3 velocity)
{
	mRigidBody->setLinearVelocity(btVector3(velocity.x, velocity.y, velocity.z));
}

void cRigidBody::ApplyForce(Vector3 force)
{
	mRigidBody->applyCentralForce(btVector3(force.x, force.y, force.z));
}

void cRigidBody::SetActive(bool active)
{
	mRigidBody->setActivationState(active);
}

void cRigidBody::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create");

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

	mRigidBody->setFriction(0.7);
	mRigidBody->setRollingFriction(0.7);

	mRigidBody->setRestitution(0.7);
}

void cRigidBody::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update");

	btTransform trans;
	mRigidBody->getMotionState()->getWorldTransform(trans);
	trans.getOpenGLMatrix(mTransform.getMatrix());

	btVector3 pos = mRigidBody->getCenterOfMassPosition();
	mPosition = Vector3(pos.x(), pos.y(), pos.z());

	btQuaternion rot = mRigidBody->getOrientation();
}

void cRigidBody::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	GLfloat c[] = { 1, 1, 1, 0 };
	glMaterialfv (GL_FRONT, GL_AMBIENT, c);

	GLUquadricObj* quad = gluNewQuadric();

	glPushMatrix();

		glMultMatrixf(mTransform.getMatrix());

		mCollisionShapeObject->RenderShape();

	glPopMatrix();
}