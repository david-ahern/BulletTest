#include "stdafx.h"
#include <iostream>
#include <fstream>

char* FileInput::debugClassName = "FileInput";
char* FileInput::defaultFilePath = "Screens\\";

FileInput::FileInput()
{
	debugPrint(debugClassName, "empty constructor");
}

FileInput::FileInput(ObjectManager* objManager)
{
	debugPrint(debugClassName, "constructor");

	mObjectManager = objManager;

	mFileName = "";
}

FileInput::~FileInput()
{
	debugPrint(debugClassName, "destructor");

	delete mFile;
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
	}
	CloseFile();

	debugPrint(debugClassName, "LoadObjects", END);

	return 1;
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
	else if(buff == "Camera")
	{
		LoadCamera();
	}
	else if(buff == "Light")
	{
		LoadLight();
	}
	else if(buff == "BulletWorld")
	{
		LoadBulletWorld();
	}
	else if(buff == "cRigidBody")
	{
		LoadCRigidBody();
	}
	else if(buff == "cSphere")
	{
		LoadCSphere();
	}
	else if(buff == "cBox")
	{
		LoadCBox();
	}
	else if(buff == "cCylinder")
	{
		LoadCCylinder();
	}
	else if(buff == "cCapsule")
	{
		LoadCCapsule();
	}
	else if(buff == "cCone")
	{
		LoadCCone();
	}
	else if(buff == "cStaticPlane")
	{
		LoadCStaticPlane();
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

void FileInput::LoadCamera()
{
	//create inputs and set to default values
	Vector3 nPosition = Vector3(0, 0, 0);
	Vector3 nRotation = Vector3(0, 0, 0);
	int nMovementSpeed = 1;
	int nRotationSpeed = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	Camera* nCamera = new Camera(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nPosition.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nPosition.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nPosition.z = atof(buff.c_str());
		}
		else if (buff == "Rotation")
		{
			// get x rot
			getline(mFile, buff, ' ');
			nRotation.x = atof(buff.c_str());

			//get y rot
			getline(mFile, buff, ' ');
			nRotation.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nRotation.z = atof(buff.c_str());
		}
		else if (buff == "MovementSpeed")
		{
			getline(mFile, buff, '\n');

			nMovementSpeed = atof(buff.c_str());
		}
		else if (buff == "RotationSpeed")
		{
			nRotationSpeed = atof(buff.c_str());
		}
	}

	nCamera->Create(nPosition, nRotation, nMovementSpeed, nRotationSpeed);
	mObjectManager->AddObject(nCamera);
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
			nGravity.x = atof(buff.c_str());

			//get y grav
			getline(mFile, buff, ' ');
			nGravity.y = atof(buff.c_str());

			// get z grav
			getline(mFile, buff, '\n');
			nGravity.z = atof(buff.c_str());
		}
	}

	nBulletWorld->Create(nGravity);
	mObjectManager->AddObject(nBulletWorld);
}

void FileInput::LoadLight()
{
	Vector3 nPosition = Vector3(0, 0, 0);
	Vector4 nAmbient = Vector4(0, 0, 0, 0);
	Vector4 nDiffuse = Vector4(0, 0, 0, 0);
	Vector4 nSpecular = Vector4(0, 0, 0, 0);
	float nMass = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	Light* nLight = new Light(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nPosition.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nPosition.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nPosition.z = atof(buff.c_str());
		}
		else if (buff == "Ambient")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nAmbient.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nAmbient.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			nAmbient.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			nAmbient.w = atof(buff.c_str());
		}
		else if (buff == "Diffuse")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nDiffuse.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nDiffuse.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			nDiffuse.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			nDiffuse.w = atof(buff.c_str());
		}
		else if (buff == "Specular")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nSpecular.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nSpecular.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			nSpecular.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			nSpecular.w = atof(buff.c_str());
		}
	}
	mObjectManager->AddObject(nLight);
	nLight->Create(nPosition, nAmbient, nDiffuse, nSpecular);
}

void FileInput::LoadCRigidBody()
{
	char* nCollisionShapeName;
	Vector3 nPosition = Vector3(0, 0, 0);
	Vector3 nRotation = Vector3(0, 0, 0);
	float nMass = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cRigidBody* nBulletRigidBody = new cRigidBody(objectName);

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
		else if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nPosition.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nPosition.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nPosition.z = atof(buff.c_str());
		}
		else if (buff == "Rotation")
		{
			// get x pos
			getline(mFile, buff, ' ');
			nRotation.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			nRotation.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			nRotation.z = atof(buff.c_str());
		}
		else if (buff == "Mass")
		{
			getline(mFile, buff, '\n');
			nMass = atof(buff.c_str());
		}
	}
	mObjectManager->AddObject(nBulletRigidBody);
	nBulletRigidBody->Create(nCollisionShapeName, nPosition, nRotation, nMass);
}

void FileInput::LoadCSphere()
{
	float radius = 1;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cSphere* nCSphere = new cSphere(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "Radius")
		{
			getline(mFile, buff, '\n');
			radius = atof(buff.c_str());
		}
	}

	nCSphere->Create(radius);
	mObjectManager->AddObject(nCSphere);
}

void FileInput::LoadCBox()
{
	Vector3 halfExtents = Vector3(1, 1, 1);

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cBox* nCBox = new cBox(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "HalfExtents")
		{
			getline(mFile, buff, ' ');
			halfExtents.x = atof(buff.c_str());

			getline(mFile, buff, ' ');
			halfExtents.y = atof(buff.c_str());

			getline(mFile, buff, '\n');
			halfExtents.z = atof(buff.c_str());
		}
	}

	nCBox->Create(halfExtents);
	mObjectManager->AddObject(nCBox);
}

void FileInput::LoadCCylinder()
{
	Vector3 halfExtents = Vector3(1, 1, 1);

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cCylinder* nCylinder = new cCylinder(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "HalfExtents")
		{
			getline(mFile, buff, ' ');
			halfExtents.x = atof(buff.c_str());

			getline(mFile, buff, ' ');
			halfExtents.y = atof(buff.c_str());

			getline(mFile, buff, '\n');
			halfExtents.z = atof(buff.c_str());
		}
	}

	nCylinder->Create(halfExtents);
	mObjectManager->AddObject(nCylinder);
}

void FileInput::LoadCCapsule()
{
	float radius = 0;
	float height = 0;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cCapsule* nCCapsule = new cCapsule(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "Radius")
		{
			getline(mFile, buff, '\n');
			radius = atof(buff.c_str());
		}
		else if(buff == "Height")
		{
			getline(mFile, buff, '\n');

			height = atof(buff.c_str());
		}
	}

	nCCapsule->Create(radius, height);
	mObjectManager->AddObject(nCCapsule);
}

void FileInput::LoadCCone()
{
	float radius = 1;
	float height = 3;

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cCone* nCCone = new cCone(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "Radius")
		{
			getline(mFile, buff, '\n');
			radius = atof(buff.c_str());
		}
		else if(buff == "Height")
		{
			getline(mFile, buff, '\n');

			height = atof(buff.c_str());
		}
	}

	nCCone->Create(radius, height);
	mObjectManager->AddObject(nCCone);
}

void FileInput::LoadCStaticPlane()
{
	Vector3 upAxis = Vector3(0, 1, 0);

	getline(mFile, buff, '\n');

	char* objectName = new char[buff.length() + 1];
	strcpy(objectName, buff.c_str());

	cStaticPlane* nCStaticPlane = new cStaticPlane(objectName);

	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if(buff == "UpAxis")
		{
			getline(mFile, buff, ' ');
			upAxis.x = atof(buff.c_str());

			getline(mFile, buff, ' ');
			upAxis.y = atof(buff.c_str());

			getline(mFile, buff, '\n');
			upAxis.z = atof(buff.c_str());
		}
	}

	nCStaticPlane->Create(upAxis);
	mObjectManager->AddObject(nCStaticPlane);
}