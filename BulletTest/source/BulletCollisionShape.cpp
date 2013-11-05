#include "stdafx.h"

char* BulletCollisionShape::debugClassName = "BulletCollisionShape";

BulletCollisionShape::BulletCollisionShape()
{
	debugPrint(debugClassName, "empty constructor");
}

BulletCollisionShape::BulletCollisionShape(char* name) : GameObject(name, BULLETCOLLISIONSHAPE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

BulletCollisionShape::~BulletCollisionShape()
{
	debugPrint(debugClassName, mObjectName, "destructor");
	mShape->~btCollisionShape();
}

void BulletCollisionShape::Create(BroadphaseNativeTypes shapeType, Dimensions& dimensions)
{
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);

	switch (shapeType)
	{
	case SPHERE_SHAPE_PROXYTYPE:
		mShape = new btSphereShape(dimensions.sRadius);
		break;
	case BOX_SHAPE_PROXYTYPE:
		mShape = new btBoxShape(btVector3(dimensions.sHalfExtents.x,
											dimensions.sHalfExtents.y,
											dimensions.sHalfExtents.z));
		break;
	case CYLINDER_SHAPE_PROXYTYPE:
		mShape = new btCylinderShape(btVector3(dimensions.sHalfExtents.x,
											dimensions.sHalfExtents.y,
											dimensions.sHalfExtents.z));
		break;
	case CAPSULE_SHAPE_PROXYTYPE:
		mShape = new btCapsuleShape(dimensions.sRadius, dimensions.sHeight);
		break;
	case CONE_SHAPE_PROXYTYPE:
		mShape = new btConeShape(dimensions.sRadius, dimensions.sHeight);
		break;
	case STATIC_PLANE_PROXYTYPE:
		mShape = new btStaticPlaneShape(btVector3(dimensions.sUpAxis.x, 
													dimensions.sUpAxis.y, 
													dimensions.sUpAxis.z), 
										btScalar(0));
		break;
	default:
		printf("invalide shapetype: cannot create collision shape\n");
	}

	debugPrint(debugClassName, mObjectName, "Create", END);
}