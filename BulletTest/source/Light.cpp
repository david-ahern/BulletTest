#include "stdafx.h"

char* Light::debugClassName = "Light";

int Light::sNumberOfLights = 0;

Light::Light()
{
	debugPrint(debugClassName, "empty constructor");
}

Light::Light(char* name) : GameObject(name, LIGHT_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

Light::~Light()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}

void Light::Create(ObjectData data)
{
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);

	switch(sNumberOfLights)
	{
	case 0:
		mLightNum = GL_LIGHT0;
		break;
	case 1:
		mLightNum = GL_LIGHT1;
		break;
	case 2:
		mLightNum = GL_LIGHT2;
		break;
	case 3:
		mLightNum = GL_LIGHT3;
		break;
	case 4:
		mLightNum = GL_LIGHT4;
		break;
	case 5:
		mLightNum = GL_LIGHT5;
		break;
	case 6:
		mLightNum = GL_LIGHT6;
		break;
	case 7:
		mLightNum = GL_LIGHT7;
		break;
	default:
		debugPrint(debugClassName, mObjectName, "Create", END);
		return;
	}

	mPosition = data.nPosition;
	mAmbient = data.nAmbient;
	mDiffuse = data.nDiffuse;
	mSpecular = data.nSpecular;

	const GLfloat GLposition[] = { mPosition.x, mPosition.y, mPosition.z, 1.0 };
	const GLfloat GLambient[] = { mAmbient.x, mAmbient.y, mAmbient.z, mAmbient.z };
	const GLfloat GLdiffuse[] = { mDiffuse.x, mDiffuse.y, mDiffuse.z, mDiffuse.w };
	const GLfloat GLspecular[] = { mSpecular.x, mSpecular.y, mSpecular.z, mSpecular.w };

	glLightfv (GL_LIGHT1, GL_AMBIENT, GLambient);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, GLdiffuse);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, GLspecular);
	glLightfv (GL_LIGHT1, GL_POSITION, GLposition);    
	glEnable (GL_LIGHT1);

	++sNumberOfLights;

	debugPrint(debugClassName, mObjectName, "Create", END);
}