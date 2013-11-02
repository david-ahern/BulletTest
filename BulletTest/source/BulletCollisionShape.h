#ifndef _BULLETCOLLISIONSHAPE_H_
#define _BULLETCOLLISIONSHAPE_H_

#include "stdafx.h"

#define SPHERE 0
#define CUBE 1
#define CYLINDER 2
#define CAPSULE 3
#define CONE 4

class GameObject;

typedef struct Dimensions
{
	btVector3	sHalfExtents;
	float		sRadius;
	float		sHeight;
	btVector3	sUpAxis;
}dimensions;

class BulletCollisionShape : public GameObject
{
private:
	static char* debugClassName;

	btCollisionShape*	mShape;

public:
	BulletCollisionShape();
	BulletCollisionShape(char* objectName);
	~BulletCollisionShape();

	void				Create(BroadphaseNativeTypes shapeType, Dimensions& dimensions);

	btCollisionShape*	GetCollisionShape() { return mShape; }
};

#endif