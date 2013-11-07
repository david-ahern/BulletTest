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

void cRigidBody::Create(char* collisionShapeName, Vector3 position, 
							Vector3 rotation, float mass)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mBulletWorld = ((BulletWorld*)mObjectManager->GetGameObject(BULLETWORLD_OBJECT))->GetWorld();

	mCollisionShapeObject = (iCollisionShape*)mObjectManager->GetGameObject(collisionShapeName);

	mCollisionShape = mCollisionShapeObject->GetCollisionShape();

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(position.x, position.y, position.z));
	startTransform.setRotation(btQuaternion(rotation.x, rotation.y, rotation.z));

	btVector3 inertia(0,0,0);
	if (mass != 0)
		mCollisionShape->calculateLocalInertia(mass, inertia);

	btMotionState* motion = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo info(mass, motion, mCollisionShape, inertia);
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

		mCollisionShapeObject->Render();

	glPopMatrix();
}