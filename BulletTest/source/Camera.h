#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "stdafx.h"

class GameObject;

class Camera: public GameObject
{
private:
	static char* debugClassName;
public:
	float zoom;

	float rotX;
	float rotY;

	float transX;
	float transZ;

	bool mouseRot;
	bool mouseMove;

	float mouseX;
	float mouseY;

	Camera(void);
	Camera(char* objectName);
	~Camera(void);

	void place();

	void rotateX(float rot);
	void rotateY(float rot);

	void updatePos(float xIncrement, float zIncrement);
	void setPos(float xPos, float zPos);

	void updateZoom(float zoomIncrement);
	void setZoom(float zoomPos);

	void trackMouse();

	void create();
};

#endif