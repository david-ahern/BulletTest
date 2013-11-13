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
	delete mFile;
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

	ObjectData data = GetDefaultDataValues();

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
		nObject = new Timer(objName);
	}
	else if(objType == "Camera")
	{
		data.objectType = CAMERA_OBJECT;
		nObject = new Camera(objName);
	}
	else if(objType == "Light")
	{
		data.objectType = LIGHT_OBJECT;
		nObject = new Light(objName);
	}
	else if(objType == "BulletWorld")
	{
		data.objectType = BULLETWORLD_OBJECT;
		nObject = new BulletWorld(objName);
	}
	else if(objType == "cRigidBody")
	{
		data.objectType = CRIGIDBODY_OBJECT;
		nObject = new cRigidBody(objName);
	}
	else if(objType == "cSphere")
	{
		data.objectType = CSPHERE_OBJECT;
		nObject = new cSphere(objName);
	}
	else if(objType == "cBox")
	{
		data.objectType = CBOX_OBJECT;
		nObject = new cBox(objName);
	}
	else if(objType == "cCylinder")
	{
		data.objectType = CCYLINDER_OBJECT;
		nObject = new cCylinder(objName);
	}
	else if(objType == "cCapsule")
	{
		data.objectType = CCAPSULE_OBJECT;
		nObject = new cCapsule(objName);
	}
	else if(objType == "cCone")
	{
		data.objectType = CCONE_OBJECT;
		nObject = new cCone(objName);
	}
	else if(objType == "cStaticPlane")
	{
		data.objectType = CSTATICPLANE_OBJECT;
		nObject = new cStaticPlane(objName);
	}
	else if(objType == "cPlayer")
	{
		data.objectType = CPLAYER_OBJECT;
		nObject = new cPlayer(objName);
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
			data.nRigidBodyName = new char[buff.length() + 1];
			strcpy(data.nRigidBodyName, buff.c_str());
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
		else if (buff == "Friction")
		{
			getline(mFile, buff, '\n');
			data.nFriction = atof(buff.c_str());
		}
		else if (buff == "RollingFriction")
		{
			getline(mFile, buff, '\n');
			data.nRollingFriction = atof(buff.c_str());
		}
		else if (buff == "Restitution")
		{
			getline(mFile, buff, '\n');
			data.nRestitution = atof(buff.c_str());
		}
	}

	mObjectManager->AddObject(nObject);
	nObject->Create(data);

	debugPrint(debugClassName, "LoadNextObject", END);
}

ObjectData GetDefaultDataValues()
{
	ObjectData d;

	d.objectType			= NO_OBJECT_TYPE;
	d.nCollisionShapeName	= "null";
	d.nRigidBodyName		= "null";
	d.nPosition				= Vector3(0, 0, 0);
	d.nRotation				= Vector3(0, 0, 0);
	d.nMass					= 1;
	d.nFriction				= 0.7;
	d.nRollingFriction		= 0.7;
	d.nRestitution			= 0.7;
	d.nRadius				= 1;
	d.nHeight				= 1;
	d.nHalfExtents			= Vector3(1, 1, 1);
	d.nMovementSpeed		= 1;
	d.nRotationSpeed		= 1;
	d.nGravity				= Vector3(0, 10, 0);
	d.nAmbient				= Vector4(0, 0, 0, 0);
	d.nDiffuse				= Vector4(0, 0, 0, 0);
	d.nSpecular				= Vector4(0, 0, 0, 0);
	d.nUpAxis				= Vector3(0, 1, 0);

	return d;
}