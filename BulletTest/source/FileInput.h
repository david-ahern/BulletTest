#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class GameObject;
class ObjectManager;

typedef struct ObjectData
{
	int objectType;

}objdata;

class FileInput
{
private:
	static char* debugClassName;
	static char* defaultFilePath;

	char*		mFileName;

	ifstream	mFile;

	string		buff;

	ObjectManager* mObjectManager;

	bool		OpenFile();
	void		CloseFile();
	void		LoadNextObject();
	
	void		LoadTimer();
	void		LoadCameraFree();
	void		LoadBulletWorld();
	void		LoadLight();
	void		LoadCRigidBody();
	void		LoadCSphere();
	void		LoadCBox();
	void		LoadCCylinder();
	void		LoadCCapsule();
	void		LoadCCone();
	void		LoadCStaticPlane();

public:
	FileInput();
	FileInput(ObjectManager* objectManager);
	~FileInput();

	bool		LoadObjects(char* fileName);
};

#endif