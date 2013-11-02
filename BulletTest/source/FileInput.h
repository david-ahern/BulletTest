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

	char*		mFileName;

	ifstream	mFile;

	ObjectManager* mObjectManager;

	bool		OpenFile();
	void		LoadNextObject();
	void		DefaultInit();

public:
	FileInput();
	FileInput(ObjectManager* objectManager);
	~FileInput();

	bool		LoadObjects(char* fileName);
};

#endif