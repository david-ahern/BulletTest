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
	Vector3 nHalfExtents;
	Vector3 nPosition;
	Vector3 nRotation;
	int		nMovementSpeed;
	int		nRotationSpeed;
	Vector3 nGravity;
	Vector4 nAmbient;
	Vector4 nDiffuse;
	Vector4 nSpecular;
	char*	nCollisionShapeName;
	char*	nRigidBodyName;
	int		nMass;
	int		nRadius;
	int		nHeight;
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
	
	Timer*			nTimer;
	Camera*			nCamera;
	BulletWorld*	nBulletWorld;
	Light*			nLight;
	cRigidBody*		nCRigidBody;
	cSphere*		nCSphere;
	cBox*			nCBox;
	cCylinder*		nCCylinder;
	cCapsule*		nCCapsule;
	cCone*			nCCone;
	cStaticPlane*	nCStaticPlane;
	cPlayerCube*	nCPlayerCube;

public:
	FileInput();
	FileInput(ObjectManager* objectManager);
	~FileInput();

	bool		LoadObjects(char* fileName);
};

#endif