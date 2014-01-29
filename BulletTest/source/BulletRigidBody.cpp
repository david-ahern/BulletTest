#include "stdafx.h"

char* BulletRigidBody::debugClassName = "BulletRigidBody";

BulletRigidBody::BulletRigidBody()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

BulletRigidBody::BulletRigidBody(char* name) : GameObject(name, BULLETRIGIDBODY_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

BulletRigidBody::~BulletRigidBody()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif

	mBody->~btRigidBody();
}

void BulletRigidBody::Create(char* collisionShapeName, Vector3 position, Vector3 rotation, float mass)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);
#endif

	mBtWorld = ((BulletWorld*)mObjectManager->GetGameObject(BULLETWORLD_OBJECT))->GetWorld();

	mShape = ((BulletCollisionShape*)mObjectManager->GetGameObject(collisionShapeName))->GetCollisionShape();

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(position.x, position.y, position.z));
	startTransform.setRotation(btQuaternion(rotation.x, rotation.y, rotation.z));

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

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create", END);
#endif
}

void BulletRigidBody::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);
#endif

	btTransform trans;
	mBody->getMotionState()->getWorldTransform(trans);

	trans.getOpenGLMatrix(mTransform.getMatrix());

	btVector3 pos = mBody->getCenterOfMassPosition();

	mPosition = Vector3(pos.x(), pos.y(), pos.z());

	btQuaternion rot = mBody->getOrientation();

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", END);
#endif
}

void BulletRigidBody::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render", BEGIN);
#endif

	GLfloat c[] = { 1, 1, 1, 0 };
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

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render", END);
#endif
}

void BulletRigidBody::SetFriction(float friction)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetFriction");
#endif

	mBody->setFriction(friction);
	mBody->setRollingFriction(friction);
}

void BulletRigidBody::SetRestitution(float restitution)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetRestitution");
#endif

	mBody->setRestitution(restitution);
}

void BulletRigidBody::SetPosition(btVector3& position)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetPosition");
#endif

	btTransform positionTransform;
	positionTransform.setIdentity();
	positionTransform.setOrigin(position);

	mBody->setCenterOfMassTransform(positionTransform);
}

void BulletRigidBody::SetVelocity(btVector3& velocity)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "SetVelocity");
#endif

	mBody->setLinearVelocity(velocity);
}

void BulletRigidBody::ApplyForce(btVector3& force)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "ApplyForce");
#endif

	mBody->applyCentralForce(force);
}