#include "stdafx.h"

char* cStaticPlane::debugClassName = "cStaticPlane";

cStaticPlane::cStaticPlane()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

cStaticPlane::cStaticPlane(char* name) : iCollisionShape(name, CSTATICPLANE_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "constructor");
#endif
}

cStaticPlane::~cStaticPlane()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}


void cStaticPlane::Create(ObjectData data)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Create");
#endif

	mUpAxis = data.nUpAxis;

	mCollisionShape = new btStaticPlaneShape(btVector3(mUpAxis.x, 
														mUpAxis.y, 
														mUpAxis.z), 
												btScalar(0));
}

void cStaticPlane::RenderShape()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Render");
#endif

	glBegin(GL_QUADS);
		glVertex3f(-1000,0,1000);
		glVertex3f(1000,0,1000);
		glVertex3f(1000,0,-1000);
		glVertex3f(-1000,0,-1000);
	glEnd();
}

