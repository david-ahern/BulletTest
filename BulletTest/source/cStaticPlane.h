#ifndef _CSTATICPLANE_H_
#define _CSTATICPLANE_H_

// Created by: 
// 

#include "stdafx.h"

class GameObject;
class iCollisionShape;

class cStaticPlane : public iCollisionShape
{
private:
	static char* debugClassName;

	Vector3				mUpAxis;
public:
	cStaticPlane();
	cStaticPlane(char* objectName);
	~cStaticPlane();

	btCollisionShape*	GetCollisionShape() { return mCollisionShape; }

	void Create(ObjectData data);
	void RenderShape();
};

#endif
