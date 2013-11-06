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
	void		DefaultInit();
	
	void		LoadTimer();
	void		LoadCameraFree();
	void		LoadBulletWorld();
	void		LoadBulletCollisionShape();
	void		LoadBulletRigidBody();
	void		LoadLight();

public:
	FileInput();
	FileInput(ObjectManager* objectManager);
	~FileInput();

	bool		LoadObjects(char* fileName);
};

#endif