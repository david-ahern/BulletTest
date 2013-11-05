#include "stdafx.h"

char* Camera::debugClassName = "Camera";

Camera::Camera(void)
{
	debugPrint(debugClassName, "empty constructor");
}

Camera::Camera(char* name) : GameObject(name, CAMERA_OBJECT)
{
	debugPrint(debugClassName, mObjectName, "constructor");
}

Camera::~Camera(void)
{

}

void Camera::create()
{
	rotX = 45;
	rotY = 0;

	transX = 0;
	transZ = 0;

	zoom = 30;

	mouseRot = false;
	mouseMove = false;
	mouseX = 0;
	mouseY = 0;
}

void Camera::place()
{
	gluLookAt(0, 10, -10, 0, 0, 0, 0, 1, 0);

	//glTranslatef(0, 0, zoom);
	//glTranslatef(transX, 0, 0);
	//glRotatef(rotX+180, 1, 0, 0);
	//glRotatef(rotY, 0, 1, 0);
	//glTranslatef(0, 0, transZ);
}

void Camera::rotateX(float rot)
{
	rotX += rot;
	if(rotX > 90)
		rotX = 90;
	else if (rotX < 1)
		rotX = 1;
}

void Camera::rotateY(float rot)
{
	rotY += rot;
	if (rotY > 360)
		rotY -= 360;
	else if(rotY < 0)
		rotY += 360;
}

void Camera::updatePos(float xInc, float zInc)
{
	transX += xInc;
	transZ += zInc;
}

void Camera::setPos(float xPos, float zPos)
{
	transX = xPos;
	transZ = zPos;
}

void Camera::updateZoom(float zoomInc)
{
	zoom += zoomInc;
}

void Camera::setZoom(float zoomPos)
{
	zoom = zoomPos;
}

void Camera::trackMouse()
{

}