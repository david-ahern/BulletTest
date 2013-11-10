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

	endLoad = false;

	if (OpenFile())
	{
		while (!endLoad)
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

	ObjectData data;

	// get objectType from file and store in objType
	getline(mFile, buff, '<');
	getline(mFile, buff, '>');
	string objType = buff;

	// get name of the object and store in objName
	getline(mFile, buff, '\n');
	char* objName = new char[buff.length() + 1];
	strcpy(objName, buff.c_str());

	// create object
	if (objType == "EndOfFile")
	{
		endLoad = true;
		return;
	}
	else if(objType == "Timer")
	{
		data.objectType = TIMER_OBJECT;
		nTimer = new Timer(objName);
	}
	else if(objType == "Camera")
	{
		data.objectType = CAMERA_OBJECT;
		nCamera = new Camera(objName);
	}
	else if(objType == "Light")
	{
		data.objectType = LIGHT_OBJECT;
		nLight = new Light(objName);
	}
	else if(objType == "BulletWorld")
	{
		data.objectType = BULLETWORLD_OBJECT;
		nBulletWorld = new BulletWorld(objName);
	}
	else if(objType == "cRigidBody")
	{
		data.objectType = CRIGIDBODY_OBJECT;
		nCRigidBody = new cRigidBody(objName);
	}
	else if(objType == "cSphere")
	{
		data.objectType = CSPHERE_OBJECT;
		nCSphere = new cSphere(objName);
	}
	else if(objType == "cBox")
	{
		data.objectType = CBOX_OBJECT;
		nCBox = new cBox(objName);
	}
	else if(objType == "cCylinder")
	{
		data.objectType = CCYLINDER_OBJECT;
		nCCylinder = new cCylinder(objName);
	}
	else if(objType == "cCapsule")
	{
		data.objectType = CCAPSULE_OBJECT;
		nCCapsule = new cCapsule(objName);
	}
	else if(objType == "cCone")
	{
		data.objectType = CCONE_OBJECT;
		nCCone = new cCone(objName);
	}
	else if(objType == "cStaticPlane")
	{
		data.objectType = CSTATICPLANE_OBJECT;
		nCStaticPlane = new cStaticPlane(objName);
	}
	else if(objType == "cPlayerCube")
	{
		data.objectType = CPLAYERCUBE_OBJECT;
		nCPlayerCube = new cPlayerCube(objName);
	}

	// get message
	while (buff != "end")
	{
		getline(mFile, buff, '<');
		getline(mFile, buff, '>');

		if (buff == "Position")
		{
			// get x pos
			getline(mFile, buff, ' ');
			data.nPosition.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			data.nPosition.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			data.nPosition.z = atof(buff.c_str());
		}
		else if (buff == "Rotation")
		{
			// get x rot
			getline(mFile, buff, ' ');
			data.nRotation.x = atof(buff.c_str());

			//get y rot
			getline(mFile, buff, ' ');
			data.nRotation.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, '\n');
			data.nRotation.z = atof(buff.c_str());
		}
		else if (buff == "MovementSpeed")
		{
			getline(mFile, buff, '\n');

			data.nMovementSpeed = atof(buff.c_str());
		}
		else if (buff == "RotationSpeed")
		{
			data.nRotationSpeed = atof(buff.c_str());
		}
		else if (buff == "Gravity")
		{
			// get x grav
			getline(mFile, buff, ' ');
			data.nGravity.x = atof(buff.c_str());

			//get y grav
			getline(mFile, buff, ' ');
			data.nGravity.y = atof(buff.c_str());

			// get z grav
			getline(mFile, buff, '\n');
			data.nGravity.z = atof(buff.c_str());
		}
		else if (buff == "Ambient")
		{
			// get x pos
			getline(mFile, buff, ' ');
			data.nAmbient.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			data.nAmbient.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			data.nAmbient.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			data.nAmbient.w = atof(buff.c_str());
		}
		else if (buff == "Diffuse")
		{
			// get x pos
			getline(mFile, buff, ' ');
			data.nDiffuse.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			data.nDiffuse.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			data.nDiffuse.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			data.nDiffuse.w = atof(buff.c_str());
		}
		else if (buff == "Specular")
		{
			// get x pos
			getline(mFile, buff, ' ');
			data.nSpecular.x = atof(buff.c_str());

			//get y pos
			getline(mFile, buff, ' ');
			data.nSpecular.y = atof(buff.c_str());

			// get z rot
			getline(mFile, buff, ' ');
			data.nSpecular.z = atof(buff.c_str());

			getline(mFile, buff, '\n');
			data.nSpecular.w = atof(buff.c_str());
		}
		else if (buff == "CollisionShape")
		{
			getline(mFile, buff, '\n');
			data.nCollisionShapeName = new char[buff.length() + 1];
			strcpy(data.nCollisionShapeName, buff.c_str());
		}
		else if (buff == "RigidBody")
		{
			getline(mFile, buff, '\n');
			data.nCollisionShapeName = new char[buff.length() + 1];
			strcpy(data.nCollisionShapeName, buff.c_str());
		}
		else if (buff == "Mass")
		{
			getline(mFile, buff, '\n');
			data.nMass = atof(buff.c_str());
		}
		else if(buff == "Radius")
		{
			getline(mFile, buff, '\n');
			data.nRadius = atof(buff.c_str());
		}
		else if(buff == "Height")
		{
			getline(mFile, buff, '\n');
			data.nHeight = atof(buff.c_str());
		}
		else if(buff == "UpAxis")
		{
			getline(mFile, buff, ' ');
			data.nUpAxis.x = atof(buff.c_str());

			getline(mFile, buff, ' ');
			data.nUpAxis.y = atof(buff.c_str());

			getline(mFile, buff, '\n');
			data.nUpAxis.z = atof(buff.c_str());
		}
		else if (buff == "HalfExtents")
		{
			getline(mFile, buff, ' ');
			data.nHalfExtents.x = atof(buff.c_str());

			getline(mFile, buff, ' ');
			data.nHalfExtents.y = atof(buff.c_str());

			getline(mFile, buff, '\n');
			data.nHalfExtents.z = atof(buff.c_str());
		}
	}


	// call create function and add to object manager
	if(data.objectType == TIMER_OBJECT)
	{
		mObjectManager->AddObject(nTimer);
	}
	else if(data.objectType == CAMERA_OBJECT)
	{
		mObjectManager->AddObject(nCamera);
		nCamera->Create(data);
	}
	else if(data.objectType == LIGHT_OBJECT)
	{
		mObjectManager->AddObject(nLight);
		nLight->Create(data);
	}
	else if(data.objectType == BULLETWORLD_OBJECT)
	{
		mObjectManager->AddObject(nBulletWorld);
		nBulletWorld->Create(data);
	}
	else if(data.objectType == CRIGIDBODY_OBJECT)
	{
		mObjectManager->AddObject(nCRigidBody);
		nCRigidBody->Create(data);
	}
	else if(data.objectType == CSPHERE_OBJECT)
	{
		mObjectManager->AddObject(nCSphere);
		nCSphere->Create(data);
	}
	else if(data.objectType == CBOX_OBJECT)
	{
		mObjectManager->AddObject(nCBox);
		nCBox->Create(data);
	}
	else if(data.objectType == CCYLINDER_OBJECT)
	{
		mObjectManager->AddObject(nCCylinder);
		nCCylinder->Create(data);
	}
	else if(data.objectType == CCAPSULE_OBJECT)
	{
		mObjectManager->AddObject(nCCapsule);
		nCCapsule->Create(data);
	}
	else if(data.objectType == CCONE_OBJECT)
	{
		mObjectManager->AddObject(nCCone);
		nCCone->Create(data);
	}
	else if(data.objectType == CSTATICPLANE_OBJECT)
	{
		mObjectManager->AddObject(nCStaticPlane);
		nCStaticPlane->Create(data);
	}
	else if(data.objectType == CPLAYERCUBE_OBJECT)
	{
		mObjectManager->AddObject(nCPlayerCube);
		nCPlayerCube->Create(data);
	}

	debugPrint(debugClassName, "LoadNextObject", END);
}
