#include "stdafx.h"

char* cInputHandler::debugClassName = "cInputHandler";

cInputHandler::cInputHandler()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "constructor");
#endif
}

cInputHandler::~cInputHandler()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "destructor");
#endif
}

void cInputHandler::KeyboardDown(unsigned char key, int x, int y)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "KeyboardDown");
#endif

	state[key] = true;

	mKeypressed = true;
}

void cInputHandler::KeyboardUp(unsigned char key, int x, int y)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "KeyboardUp");
#endif

	state[key] = false;

	if (state.size() == 0)
		mKeypressed = false;
}

void cInputHandler::MouseRead(int button, int state, int x, int y)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "MouseRead");
#endif

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
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "MouseTrack");
#endif

	Vector2 temp = Vector2(x, y);

	mMouseTrack = temp - mMousePos;

	mMousePos = temp;
}

bool cInputHandler::IsDown(unsigned char key)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "IsDown", key);
#endif

	if (state[key])
		return true;
	else
		return false;
}

Vector2 cInputHandler::GetMouseTrack(bool clearTrack)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "GetMouseTrack");
#endif

	if (!clearTrack)
		return mMouseTrack;

	Vector2 temp = mMouseTrack;

	mMouseTrack = Vector2(0, 0);

	return temp;
}

void cInputHandler::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Init");
#endif

	mMouseDown = NO_MOUSE;
	mKeypressed = false;

	mMousePos = Vector2(0, 0);
	mMouseTrack = Vector2(0, 0);
}