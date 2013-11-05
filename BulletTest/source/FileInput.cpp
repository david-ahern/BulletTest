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

void FileInput::CloseFile()
{
	if(mFile.is_open())
		mFile.close();
}

void FileInput::DefaultInit()
{
	debugPrint(debugClassName, "DefaultInit", BEGIN);

	Timer* timer = new Timer("gameTimer");
	mObjectManager->AddObject(timer);

	BulletWorld* bulletWorld = new BulletWorld("bulletWorld");
	bulletWorld->Create(Vector3(0, -10, 0));
	mObjectManager->AddObject(bulletWorld);

	CameraFree* camera = new CameraFree("camera");
	camera->Create(Vector3(0, 10, 10), Vector3(0, 0, 0), 1, 1);
	mObjectManager->AddObject(camera);

	/*Light* light = new Light("light");
	light->Create(Vector3(10, 10, -10), Vector4(1,1,1,1), Vector4(1,1,1,1), Vector4(1,1,1,1));
	mObjectManager->AddObject(light);*/

	//create a floor
	BulletCollisionShape* floorShape = new BulletCollisionShape("floorShape");
	Dimensions dFloor;
	dFloor.sUpAxis = btVector3(0, 1, 0);
	floorShape->Create(STATIC_PLANE_PROXYTYPE, dFloor);
	mObjectManager->AddObject(floorShape);

	BulletRigidBody* floorBody = new BulletRigidBody("floorBody");
	mObjectManager->AddObject(floorBody);
	floorBody->Create("floorShape", Vector3(0,0,0), 0);

	// create a body
	BulletCollisionShape* ballShape = new BulletCollisionShape("ballShape");
	Dimensions dBall;
	dBall.sRadius = 1;
	ballShape->Create(SPHERE_SHAPE_PROXYTYPE, dBall);
	mObjectManager->AddObject(ballShape);

	BulletRigidBody* ballBody = new BulletRigidBody("ballBody");
	mObjectManager->AddObject(ballBody);
	ballBody->Create("ballShape", Vector3(0, 10, 0), 1);

	BulletCollisionShape* boxShape = new BulletCollisionShape("boxShape");
	Dimensions dBox;
	dBox.sHalfExtents = btVector3(1, 1, 1);
	boxShape->Create(BOX_SHAPE_PROXYTYPE, dBox);
	mObjectManager->AddObject(boxShape);

	BulletRigidBody* boxBody = new BulletRigidBody("boxBody");
	mObjectManager->AddObject(boxBody);
	boxBody->Create("boxShape", Vector3(2, 10, 0), 1);

	debugPrint(debugClassName, "DefaultInit", END);
}


void FileInput::LoadNextObject()
{
	debugPrint(debugClassName, "LoadNextObject", BEGIN);

	getline(mFile, buff, '<');
	getline(mFile, buff, '>');

	if(buff == "Timer")
	{
		LoadTimer();
	}
	else if(buff == "CameraFree")
	{
		LoadCameraFree();
	}
	else if(buff == "BulletWorld")
	{
		LoadBulletWorld();
	}
	else if(buff == "BulletCollisionShape")
	{
		LoadBulletCollisionShape();
	}
	else if(buff == "BulletRigidBody")
	{
		LoadBulletRigidBody();
	}

	debugPrint(debugClassName, "LoadNextObject", END);
}

void FileInput::LoadTimer()
{
	// get next, should be objects name
	getline(mFile, buff, '\n');

	// convert buff to char*
	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	// create new timer and add to object list
	Timer* nTimer = new Timer(objectName);
	mObjectManager->AddObject(nTimer);

	//get the end tag so that the next object can continue
	getline(mFile, buff, '<');
	getline(mFile, buff, '>');
}

void FileInput::LoadCameraFree()
{
	//create inputs and set to default values
	Vector3 nPosition = Vector3(0, 0, 0);
	Vector3 nRotation = Vector3(0, 0, 0);
	int nMovementSpeed = 1;
	int nRotationSpeed = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	CameraFree* nCameraFree = new CameraFree(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nPosition.x = atoi(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nPosition.y = atoi(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nPosition.z = atoi(buff.c_str());
		}
		else if (buff == "Rotation")
		{
			// get x rot
			getline(mFile, buff, ' ');
			nRotation.x = atoi(buff.c_str());

			//get y rot
			getline(mFile, buff, ' ');
			nRotation.y = atoi(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nRotation.z = atoi(buff.c_str());
		}
		else if (buff == "MovementSpeed")
		{
			getline(mFile, buff, '\n');

			nMovementSpeed = atoi(buff.c_str());
		}
		else if (buff == "RotationSpeed")
		{
			nRotationSpeed = atoi(buff.c_str());
		}
	}

	nCameraFree->Create(nPosition, nRotation, nMovementSpeed, nRotationSpeed);
	mObjectManager->AddObject(nCameraFree);
}

void FileInput::LoadBulletWorld()
{
	Vector3 nGravity = Vector3(0, 0, 0);

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	BulletWorld* nBulletWorld = new BulletWorld(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Gravity")
		{
			// get x grav
			getline(mFile, buff, ' ');
			nGravity.x = atoi(buff.c_str());

			//get y grav
			getline(mFile, buff, ' ');
			nGravity.y = atoi(buff.c_str());

			// get z grav
			getline(mFile, buff, '\n');
			nGravity.z = atoi(buff.c_str());
		}
	}

	nBulletWorld->Create(nGravity);
	mObjectManager->AddObject(nBulletWorld);
}

void FileInput::LoadBulletCollisionShape()
{
	BroadphaseNativeTypes nShape = SPHERE_SHAPE_PROXYTYPE;
	Dimensions nDimensions;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	BulletCollisionShape* nBulletCollisionShape = new BulletCollisionShape(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Shape")
		{
			getline(mFile, buff, '\n');

			if (buff == "PLANE")
				nShape = STATIC_PLANE_PROXYTYPE;
			else if(buff == "SPHERE")
				nShape = SPHERE_SHAPE_PROXYTYPE;
			else if(buff == "BOX")
				nShape = BOX_SHAPE_PROXYTYPE;
			else if(buff == "CAPSULE")
				nShape = CAPSULE_SHAPE_PROXYTYPE;
			else if(buff == "CYLINDER")
				nShape = CYLINDER_SHAPE_PROXYTYPE;
			else if(buff == "CONE")
				nShape = CONE_SHAPE_PROXYTYPE;
		}
		else if(buff == "UpAxis")
		{
			getline(mFile, buff, ' ');
			nDimensions.sUpAxis.x = atoi(buff.c_str());

			getline(mFile, buff, ' ');
			nDimensions.sUpAxis.y = atoi(buff.c_str());

			getline(mFile, buff, '\n');
			nDimensions.sUpAxis.z = atoi(buff.c_str());
		}
		else if(buff == "Radius")
		{
			getline(mFile, buff, '\n');
			nDimensions.sRadius = atoi(buff.c_str());
		}
		else if(buff == "HalfExtents")
		{
			getline(mFile, buff, ' ');
			nDimensions.sHalfExtents.x = atoi(buff.c_str());

			getline(mFile, buff, ' ');
			nDimensions.sHalfExtents.y = atoi(buff.c_str());

			getline(mFile, buff, '\n');
			nDimensions.sHalfExtents.z = atoi(buff.c_str());
		}
		else if(buff == "Height")
		{
			getline(mFile, buff, '\n');

			nDimensions.sHeight = atoi(buff.c_str());
		}
	}

	nBulletCollisionShape->Create(nShape, nDimensions);
	mObjectManager->AddObject(nBulletCollisionShape);
}

void FileInput::LoadBulletRigidBody()
{
	char* nCollisionShapeName;
	Vector3 nPosition = Vector3(0, 0, 0);
	float nMass = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	BulletRigidBody* nBulletRigidBody = new BulletRigidBody(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "CollisionShape")
		{
			getline(mFile, buff, '\n');
			nCollisionShapeName = new char[buff.length() + 1];
			strcpy(nCollisionShapeName, buff.c_str());
		}
		if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nPosition.x = atoi(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nPosition.y = atoi(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nPosition.z = atoi(buff.c_str());
		}
		if (buff == "Mass")
		{
			getline(mFile, buff, '\n');
			nMass = atoi(buff.c_str());
		}
	}
	mObjectManager->AddObject(nBulletRigidBody);
	nBulletRigidBody->Create(nCollisionShapeName, nPosition, nMass);
}