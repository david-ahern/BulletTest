#include "stdafx.h"

char* Light::debugClassName = "Light";

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

void Light::Create(Vector3 _position, Vector4 _ambient, Vector4 _diffuse, Vector4 _specular)
{
	debugPrint(debugClassName, mObjectName, "Create", BEGIN);

	mPosition = _position;
	mAmbient = _ambient;
	mDiffuse = _diffuse;
	mSpecular = _specular;

	const GLfloat GLposition[] = { mPosition.x, mPosition.y, mPosition.z, 1.0 };
	const GLfloat GLambient[] = { mAmbient.x, mAmbient.y, mAmbient.z, mAmbient.z };
	const GLfloat GLdiffuse[] = { mDiffuse.x, mDiffuse.y, mDiffuse.z, mDiffuse.w };
	const GLfloat GLspecular[] = { mSpecular.x, mSpecular.y, mSpecular.z, mSpecular.w };

	glLightfv (GL_LIGHT1, GL_AMBIENT, GLambient);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, GLdiffuse);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, GLspecular);
	glLightfv (GL_LIGHT1, GL_POSITION, GLposition);    
	glEnable (GL_LIGHT1);
	glEnable (GL_LIGHTING);

	debugPrint(debugClassName, mObjectName, "Create", END);
}