#ifndef BULLET_ENGINE_HANDLER

#include <cstdio>
#include <vector>

#include "Timer.h"

#include "src\btBulletDynamicsCommon.h"
#include "src\btBulletCollisionCommon.h"

#define PI_LIMIT_THING SIMD_HALF_PI * 1.7f

struct bulletObject
{
	int id;
	float r,g,b;
	btRigidBody* body;
	bulletObject(btRigidBody* b, int i, float r0, float g0, float b0) : body(b), id(i), r(r0), g(g0), b(b0){}
};

struct bulletCompoundBody
{
	int id;
	float r,g,b;
	btRigidBody* body;
	std::vector<float> masses;
	bulletCompoundBody(btRigidBody* b, int i, float r0, float g0, float b0, std::vector<float> mass) : body(b), id(i), r(r0), b(b0), g(g0), masses(mass){}
};

class BulletEngineHandler
{
private:
	btDynamicsWorld* world;

	btDispatcher* dispatcher;
	btBroadphaseInterface* broadphase;
	btConstraintSolver* solver;
	btCollisionConfiguration* collisionConfig;

	Timer timer;

	inline btRigidBody* createLocalRigidBody(float mass, btVector3* position, btCollisionShape* shape);
	inline void setDefaultProperties(btRigidBody* body);

	bool lock2D;

public:


	std::vector<bulletObject*> bodies;

	BulletEngineHandler(void);
	~BulletEngineHandler(void);

	// starts timer, call at end of init
	void startPhysics(void);

	void stepSimulation(void);

	// create default world as a flat plane
	void createWorld(void);

	btDynamicsWorld* getDynamicsWorld();

	void removeBody(btRigidBody* body);

	// set gravity
	void setWorldGravity(float xGrav, float yGrav, float zGrav);
	void setWorldGravity(btVector3* gravity);

	// add default plane (floor plane)
	btRigidBody* addPlane(void);
	// add plane with properties
	btRigidBody* addPlane(float xPos, float yPos, float zPos, float xUp, float yUp, float zUp);

	btRigidBody* createBody(btCollisionShape* shape, btVector3* position, float mass);

	btRigidBody* createCompoundShape(float mass, btVector3* position);
	void addShapeToCompound(btCompoundShape* compoundShape, btCollisionShape* newShape, btVector3* localPosition);

	btHingeConstraint* createHingeConstraint(btRigidBody* bodyA, btRigidBody* bodyB, btVector3* length, float pivotRatio, float rotationAngleHalf);

};
#endif

