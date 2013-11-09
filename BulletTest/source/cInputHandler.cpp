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
	++mNumKeysPressed;
}

void cInputHandler::KeyboardUp(unsigned char key, int x, int y)
{
	debugPrint(debugClassName, "KeyboardUp");

	state[key] = false;

	--mNumKeysPressed;
	if (mNumKeysPressed = 0)
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
	if (state[key])
		return true;
	else
		return false;
}

void cInputHandler::Init()
{
	debugPrint(debugClassName, "Init");

	Reset();
}

void cInputHandler::Reset()
{
	debugPrint(debugClassName, "Reset");

	state['a'] = false;
	state['b'] = false;
	state['c'] = false;
	state['d'] = false;
	state['e'] = false;
	state['f'] = false;
	state['g'] = false;
	state['h'] = false;
	state['i'] = false;
	state['j'] = false;
	state['k'] = false;
	state['l'] = false;
	state['m'] = false;
	state['n'] = false;
	state['o'] = false;
	state['p'] = false;
	state['q'] = false;
	state['r'] = false;
	state['s'] = false;
	state['t'] = false;
	state['u'] = false;
	state['v'] = false;
	state['w'] = false;
	state['x'] = false;
	state['y'] = false;
	state['z'] = false;
	state[' '] = false;
	

	mMousePos = Vector2(0, 0);
	mMouseTrack = Vector2(0, 0);
}