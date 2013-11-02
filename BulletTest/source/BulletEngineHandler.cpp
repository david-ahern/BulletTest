#include "BulletEngineHandler.h"

BulletEngineHandler::BulletEngineHandler(void)
{
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfig);
	broadphase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();

	world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

	lock2D = false;

	setWorldGravity(new btVector3(0, -10, 0));
}

BulletEngineHandler::~BulletEngineHandler(void)
{
	// housekeeping
	for(int i = world->getNumCollisionObjects()-1; i>=0; --i)
	{
		btCollisionObject* obj = world->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			delete body->getMotionState();
		}
		world->removeCollisionObject( obj );
		delete obj;
	}

	bodies.empty();
	/*for(int i = bodies.size()-1; i >= 0; --i)
	{
		delete bodies[i];
	}*/

	delete dispatcher;
	delete collisionConfig;
	delete solver;
	delete broadphase;
	delete world;
}

void BulletEngineHandler::startPhysics(void)
{
	timer.startTimer();
}

void BulletEngineHandler::stepSimulation(void)
{
	world->stepSimulation(btScalar(timer.getStep()));
}
 
void BulletEngineHandler::createWorld(void)
{
	
}

btDynamicsWorld* BulletEngineHandler::getDynamicsWorld()
{
	return world;
}

void BulletEngineHandler::removeBody(btRigidBody* body)
{
	for (int i = bodies.size()-1; i > -1; --i)
	{
		if (bodies[i]->body == body)
		{
			bodies.erase(bodies.begin()+i);
			world->removeRigidBody(body);
			bodies.end();
			return;
		}
	}
	printf("Did not find the body\n");
}

void BulletEngineHandler::setWorldGravity(float xGrav, float yGrav, float zGrav)
{
	world->setGravity(btVector3(xGrav, yGrav, zGrav));
}

void BulletEngineHandler::setWorldGravity(btVector3* newGravity)
{
	world->setGravity(*newGravity);
}

inline btRigidBody* BulletEngineHandler::createLocalRigidBody(float mass, btVector3 *position, btCollisionShape* shape)
{
	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(*position);

	btVector3 inertia(0,0,0);
	if (mass != 0)
		shape->calculateLocalInertia(mass,inertia);

	// set up motion state in bullet
	btMotionState* motion = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo info(mass, motion, shape, inertia);
	btRigidBody* body = new btRigidBody(info);

	setDefaultProperties(body);

	world->addRigidBody(body);

	return body;
}

inline void BulletEngineHandler::setDefaultProperties(btRigidBody* body)
{
	body->setFriction(0.9);
	body->setRollingFriction(0.9);

	// Always keep restitution <= 1
	// if restitution > 1 massive amounts of energy are created in collision response
	body->setRestitution(0.6);

	if (lock2D)
	{
		body->setLinearFactor(btVector3(1, 1, 0));
		body->setAngularFactor(btVector3(0, 0, 1));
	}
}

btRigidBody* BulletEngineHandler::addPlane(void)
{
	btVector3 position(0, 0, 0);

	// create object with y-axis as up
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(0,1,0), btScalar(0));

	btRigidBody* body = createLocalRigidBody(0, &position, plane);
	
	bodies.push_back(new bulletObject(body, 0, 1, 1, 1));

	return body;
}

btRigidBody* BulletEngineHandler::addPlane(float xPos, float yPos, float zPos, float xUp, float yUp, float zUp)
{
	btVector3 position(xPos, yPos, zPos);

	// create object
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(xUp,yUp,zUp), btScalar(0));

	// create rigid body and apply properties
	btRigidBody* body = createLocalRigidBody(0, &position, plane);

	// add plane to world and body list
	bodies.push_back(new bulletObject(body, 0, 1, 1, 1));

	return body;
}

btRigidBody* BulletEngineHandler::createBody(btCollisionShape* shape, btVector3* position, float mass)
{
	btRigidBody* body = createLocalRigidBody(mass, position, shape);

	bodies.push_back(new bulletObject(body, 0, 1, 0, 0));

	return body;
}


btRigidBody* BulletEngineHandler::createCompoundShape(float mass, btVector3* position)
{
	// create compound shape object
	btCompoundShape* cShape = new btCompoundShape();

	btTransform t;
	t.setIdentity();

	cShape->addChildShape(t, new btBoxShape(btVector3(0,0,0)));

	// create rigid body from compound shape
	btRigidBody* compShape = createLocalRigidBody(mass,position, cShape);
	bodies.push_back(new bulletObject(compShape, 0, 1, 0, 0));

	return compShape;
}


//btRigidBody* BulletEngineHandler::addShapeToCompound(btRigidBody* oldCompoundBody, btCollisionShape* newShape, btVector3* localPosition, float mass)
void BulletEngineHandler::addShapeToCompound(btCompoundShape* compoundShape, btCollisionShape* newShape, btVector3* localPosition)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(*localPosition);

	compoundShape->addChildShape(t, newShape);
}

btHingeConstraint* BulletEngineHandler::createHingeConstraint(btRigidBody* bodyA, btRigidBody* bodyB, btVector3* length, float pivotRatio, float rotationAngle)
{
	// ratio should be between 0 and 1, and defines the point along the constraint the pivot lies
	// set to 1 to place pivot at static object, 0 at swinging object (although why would you do that?!)
	// bodyA is swinging object, bodyB would be static (maybe)

	float invRatio = 1-pivotRatio;

	btVector3 axisA(0.f, 0.f, 1.f); 
	btVector3 axisB(0.f, 0.f, 1.f); 

	btVector3 pivotA(length->x()*pivotRatio, length->y()*pivotRatio, length->z()*pivotRatio);
	btVector3 pivotB(-length->x()*invRatio, -length->y()*invRatio, -length->z()*invRatio);

	btHingeConstraint* spHingeDynAB = new btHingeConstraint(*bodyA, *bodyB, pivotA, pivotB, axisA, axisB);
	float angleRads = rotationAngle*(SIMD_PI/180);
	spHingeDynAB->setLimit(-angleRads, angleRads);

	// add constraint to world
	world->addConstraint(spHingeDynAB, true);

	return NULL;
}