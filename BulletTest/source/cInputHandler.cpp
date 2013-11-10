#include "stdafx.h"

char* cInputHandler::debugClassName = "cInputHandler";

cInputHandler::cInputHandler()
{
	debugPrint(debugClassName, "constructor");
}

cInputHandler::~cInputHandler()
{
	debugPrint(debugClassName, "destructor");
}

void cInputHandler::KeyboardDown(unsigned char key, int x, int y)
{
	debugPrint(debugClassName, "KeyboardDown");

	state[key] = true;

	mKeypressed = true;
}

void cInputHandler::KeyboardUp(unsigned char key, int x, int y)
{
	debugPrint(debugClassName, "KeyboardUp");

	state[key] = false;

	if (state.size() > 0)
		mKeypressed = false;
}

void cInputHandler::MouseRead(int button, int state, int x, int y)
{
	debugPrint(debugClassName, "MouseRead");

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mMouseDown = LEFT_MOUSE;
		mMousePos = Vector2(x, y);
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		mMouseDown = NO_MOUSE;
	}
	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		mMouseDown = MIDDLE_MOUSE;
		mMousePos = Vector2(x, y);
	}
	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
	{
		mMouseDown = NO_MOUSE;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		mMouseDown = RIGHT_MOUSE;
		mMousePos = Vector2(x, y);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		mMouseDown = NO_MOUSE;
	}
}

void cInputHandler::MouseTrack(int x, int y)
{
	debugPrint(debugClassName, "MouseTrack");

	Vector2 temp = Vector2(x, y);

	mMouseTrack = temp - mMousePos;

	mMousePos = temp;
}

bool cInputHandler::IsDown(unsigned char key)
{
	debugPrint(debugClassName, "IsDown", key);

	if (state[key])
		return true;
	else
		return false;
}

Vector2 cInputHandler::GetMouseTrack(bool clearTrack)
{
	if (!clearTrack)
		return mMouseTrack;

	Vector2 temp = mMouseTrack;

	mMouseTrack = Vector2(0, 0);

	return temp;
}

void cInputHandler::Init()
{
	debugPrint(debugClassName, "Init");

	mMouseDown = NO_MOUSE;
	mKeypressed = false;

	mMousePos = Vector2(0, 0);
	mMouseTrack = Vector2(0, 0);
}