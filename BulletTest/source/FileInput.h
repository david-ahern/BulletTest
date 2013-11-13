#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class GameObject;
class ObjectManager;
class Timer;
class Camera;
class Light;
class BulletWorld;
class cRigidBody;
class cSphere;
class cBox;
class cCylinder;
class cCapsule;
class cCone;
class cStaticPlane;
class cPlayerCube;

typedef struct ObjectData
{
	int		objectType;
	char*	nCollisionShapeName;
	char*	nRigidBodyName;
	Vector3 nPosition;
	Vector3 nRotation;
	float	nMass;
	float	nFriction;
	float	nRollingFriction;
	float	nRestitution;
	float	nRadius;
	float	nHeight;
	Vector3 nHalfExtents;
	float	nMovementSpeed;
	float	nRotationSpeed;
	Vector3 nGravity;
	Vector4 nAmbient;
	Vector4 nDiffuse;
	Vector4 nSpecular;
	Vector3 nUpAxis;
}objdata;

class FileInput
{
private:
	static char* debugClassName;
	static char* defaultFilePath;

	char*		mFileName;
	ifstream	mFile;
	string		buff;

	bool		endLoad;

	ObjectManager* mObjectManager;

	bool		OpenFile();
	void		CloseFile();
	void		LoadNextObject();

	

	GameObject*		nObject;

public:
	FileInput();
	FileInput(ObjectManager* objectManager);
	~FileInput();

	bool		LoadObjects(char* fileName);
};

extern ObjectData GetDefaultDataValues();

#endif