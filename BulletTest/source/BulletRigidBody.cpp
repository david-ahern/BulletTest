#include "stdafx.h"

char* BulletRigidBody::debugClassName = "BulletRigidBody";

BulletRigidBody::BulletRigidBody()
{
	debugPrint(debugClassName, "empty constructor");
}

BulletRigidBody::BulletRigidBody(char* name) : GameObject(name, BULLETRIGIDBODY_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

BulletRigidBody::~BulletRigidBody()
{
	debugPrint(debugClassName, mObjectName, "destructor");

	mBody->~btRigidBody();
}

void BulletRigidBody::Create(char* collisionShapeName, btVector3& position, float mass)
{
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);

	mBtWorld = ((BulletWorld*)mObjectManager->GetGameObject("bulletWorld"))->GetWorld();

	mShape = ((BulletCollisionShape*)mObjectManager->GetGameObject(collisionShapeName))->GetCollisionShape();

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(position);

	btVector3 inertia(0,0,0);
	if (mass != 0)
		mShape->calculateLocalInertia(mass, inertia);

	btMotionState* motion = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo info(mass, motion, mShape, inertia);
	mBody = new btRigidBody(info);

	mBtWorld->addRigidBody(mBody);

	mBody->setFriction(0.7);
	mBody->setRollingFriction(0.7);

	mBody->setRestitution(0.7);

	debugPrint(debugClassName, mObjectName, "Create", END);
}

void BulletRigidBody::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);

	btTransform trans;
	mBody->getMotionState()->getWorldTransform(trans);

	trans.getOpenGLMatrix(mTransform.getMatrix());

	btVector3 pos = mBody->getCenterOfMassPosition();

	mPosition = Vector3(pos.x(), pos.y(), pos.z());

	debugPrint(debugClassName, mObjectName, "Update", END);
}

void BulletRigidBody::Render()
{
	debugPrint(debugClassName, mObjectName, "Render", BEGIN);

	GLfloat c[] = { 1, 1, 1, 0.0f };
	glMaterialfv (GL_FRONT, GL_AMBIENT, c);

	GLUquadricObj* quad = gluNewQuadric();

	glPushMatrix();

		glMultMatrixf(mTransform.getMatrix());
		
		if(mBody->getCollisionShape()->getShapeType() == SPHERE_SHAPE_PROXYTYPE)
		{
			glutSolidSphere(((btSphereShape*)mBody->getCollisionShape())->getRadius(), 10, 10);
		}
		else if(mBody->getCollisionShape()->getShapeType() == BOX_SHAPE_PROXYTYPE)
		{
			btVector3 size = ((btBoxShape*)mBody->getCollisionShape())->getHalfExtentsWithMargin();

			glScalef(size.x(), size.y(), size.z());
			glutSolidCube(2);
		}
		else if(mBody->getCollisionShape()->getShapeType() == CYLINDER_SHAPE_PROXYTYPE)
		{
			btVector3 size = ((btCylinderShape*)mBody->getCollisionShape())->getHalfExtentsWithMargin();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				gluCylinder(quad, size.x(), size.y(), size.z(), 10, 10);
			glPopMatrix();
			glPushMatrix();
				glRotatef(90, -1, 0, 0);
				gluCylinder(quad, size.x(), size.y(), size.z(), 10, 10);
			glPopMatrix();
		}
		else if(mBody->getCollisionShape()->getShapeType() == CAPSULE_SHAPE_PROXYTYPE)
		{
			float radius = ((btCapsuleShape*)mBody->getCollisionShape())->getRadius();
			float height = ((btCapsuleShape*)mBody->getCollisionShape())->getHalfHeight();

			glPushMatrix();
				glRotatef(90,1,0,0);
				gluCylinder(quad, radius, radius, height, 10, 10);
				glTranslatef(0, 0, height);
				glutSolidSphere(radius, 10, 10);
			glPopMatrix();
			glPushMatrix();
				glRotatef(90,-1,0,0);
				gluCylinder(quad, radius, radius, height, 10, 10);
				glTranslatef(0, 0, height);
				glutSolidSphere(radius, 10, 10);
			glPopMatrix();
		}
		else if(mBody->getCollisionShape()->getShapeType() == CONE_SHAPE_PROXYTYPE)
		{
			float radius = ((btConeShape*)mBody->getCollisionShape())->getRadius();
			float height = ((btConeShape*)mBody->getCollisionShape())->getHeight();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				gluCylinder(quad, radius/2, radius, height/2, 10, 5);
			glPopMatrix();
			glPushMatrix();
				glRotatef(90, -1, 0, 0);
				gluCylinder(quad, radius/2, 0, height/2, 10, 5);
			glPopMatrix();
		}
		else if(mBody->getCollisionShape()->getShapeType() == STATIC_PLANE_PROXYTYPE)
		{
			glBegin(GL_QUADS);
				glVertex3f(-1000,0,1000);
				glVertex3f(1000,0,1000);
				glVertex3f(1000,0,-1000);
				glVertex3f(-1000,0,-1000);
			glEnd();
		}
		else
		{
			printf("invalid shape type: cannot draw object\n");
		}
	glPopMatrix();

	debugPrint(debugClassName, mObjectName, "Render", END);
}

void BulletRigidBody::SetFriction(float friction)
{
	debugPrint(debugClassName, mObjectName, "SetFriction");

	mBody->setFriction(friction);
	mBody->setRollingFriction(friction);
}

void BulletRigidBody::SetRestitution(float restitution)
{
	debugPrint(debugClassName, mObjectName, "SetRestitution");

	mBody->setRestitution(restitution);
}

void BulletRigidBody::SetPosition(btVector3& position)
{
	debugPrint(debugClassName, mObjectName, "SetPosition");

	btTransform positionTransform;
	positionTransform.setIdentity();
	positionTransform.setOrigin(position);

	mBody->setCenterOfMassTransform(positionTransform);
}

void BulletRigidBody::SetVelocity(btVector3& velocity)
{
	debugPrint(debugClassName, mObjectName, "SetVelocity");

	mBody->setLinearVelocity(velocity);
}

void BulletRigidBody::ApplyForce(btVector3& force)
{
	debugPrint(debugClassName, mObjectName, "ApplyForce");

	mBody->applyCentralForce(force);
}