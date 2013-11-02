#include "stdafx.h"
#include <iostream>
#include <fstream>

char* FileInput::debugClassName = "FileInput";

FileInput::FileInput()
{
	debugPrint(debugClassName, "empty constructor");
}

FileInput::FileInput(ObjectManager* objManager)
{
	debugPrint(debugClassName, "constructor");

	mObjectManager = objManager;
}

FileInput::~FileInput()
{
	debugPrint(debugClassName, "destructor");

	delete mFile;
}


bool FileInput::LoadObjects(char* _fileName)
{
	debugPrint(debugClassName, "LoadObjects", BEGIN);

	mFileName = _fileName;
	if (OpenFile())
	{
		while (!mFile.eof())
		{
			LoadNextObject();
		}
	}
	else
	{
		debugPrint("Error loading file", mFileName);
		DefaultInit();
	}

	debugPrint(debugClassName, "LoadObjects", END);

	return 1;
}

bool FileInput::OpenFile()
{
	debugPrint(debugClassName, "OpenFile");
	mFile.open(mFileName);

	if(mFile.is_open())
		return true;
	else
		return false;
}


void FileInput::LoadNextObject()
{
	debugPrint(debugClassName, "LoadNextObject", BEGIN);
	//ObjectData returnData;

	//string buff;

	//getline(file, buff, '<');
	//getline(file, buff, '>');

	//if (buff == tags.start)
	//{

	//}

	//printf(line);

	debugPrint(debugClassName, "LoadNextObject", END);
}

void FileInput::DefaultInit()
{
	debugPrint(debugClassName, "DefaultInit", BEGIN);

	Timer* timer = new Timer("gameTimer");
	mObjectManager->AddObject(timer);

	BulletWorld* bulletWorld = new BulletWorld("bulletWorld");
	bulletWorld->Create(Vector3(0, -10, 0));
	mObjectManager->AddObject(bulletWorld);

	Camera* camera = new Camera("camera");
	camera->Create();
	mObjectManager->AddObject(camera);

	Light* light = new Light("light");
	light->Create(Vector3(10, 10, -10), Vector4(1,1,1,1), Vector4(1,1,1,1), Vector4(1,1,1,1));
	mObjectManager->AddObject(light);

	//create a floor
	BulletCollisionShape* floorShape = new BulletCollisionShape("floorShape");
	Dimensions dFloor;
	dFloor.sHalfExtents = btVector3(100, 1, 100);
	floorShape->Create(BOX_SHAPE_PROXYTYPE, dFloor);
	mObjectManager->AddObject(floorShape);

	BulletRigidBody* floorBody = new BulletRigidBody("floorBody");
	mObjectManager->AddObject(floorBody);
	floorBody->Create("floorShape", btVector3(0,0,0), 0);

	// create a body
	BulletCollisionShape* ballShape = new BulletCollisionShape("ballShape");
	Dimensions dBall;
	dBall.sRadius = 1;
	ballShape->Create(SPHERE_SHAPE_PROXYTYPE, dBall);
	mObjectManager->AddObject(ballShape);

	BulletRigidBody* ballBody = new BulletRigidBody("ballBody");
	mObjectManager->AddObject(ballBody);
	ballBody->Create("ballShape", btVector3(0, 10, 0), 1);

	debugPrint(debugClassName, "DefaultInit", END);
}