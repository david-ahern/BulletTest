#include "stdafx.h"

char* cStaticPlane::debugClassName = "cStaticPlane";

cStaticPlane::cStaticPlane()
{
	debugPrint(debugClassName, "empty constructor");
}

cStaticPlane::cStaticPlane(char* name) : iCollisionShape(name, CSTATICPLANE_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

cStaticPlane::~cStaticPlane()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}


void cStaticPlane::Create(Vector3 upAxis)
{
	debugPrint(debugClassName, mObjectName, "Create");

	mUpAxis = upAxis;

	mCollisionShape = new btStaticPlaneShape(btVector3(mUpAxis.x, 
														mUpAxis.y, 
														mUpAxis.z), 
												btScalar(0));
}

void cStaticPlane::Render()
{
	debugPrint(debugClassName, mObjectName, "Render");

	glBegin(GL_QUADS);
		glVertex3f(-1000,0,1000);
		glVertex3f(1000,0,1000);
		glVertex3f(1000,0,-1000);
		glVertex3f(-1000,0,-1000);
	glEnd();
}

