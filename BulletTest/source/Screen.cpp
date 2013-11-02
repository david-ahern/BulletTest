#include "stdafx.h"

char* Screen::debugClassName = "Screen";

Screen::Screen()
{
	debugPrint(debugClassName, "empty base constructor");
}

Screen::Screen(char* name)
{
	debugPrint(debugClassName, name, "base constructor");

	mScreenName = name;

	mIsActive = false;
	mIsInputActive = false;
	mIsVisible = false;
}

Screen::~Screen()
{
	debugPrint(debugClassName, mScreenName, "base destructor");
}

void Screen::Init()
{
	debugPrint(debugClassName, mScreenName, "default Init");
}

void Screen::Update()
{
	debugPrint(debugClassName, mScreenName, "default Update");
}

void Screen::Render()
{
	debugPrint(debugClassName, mScreenName, "default Render");
}

void Screen::KeyboardRead(unsigned char key, int x, int y)
{
	debugPrint(debugClassName, mScreenName, "default KeyboardRead");
}

void Screen::MouseRead(int button, int state, int x, int y)
{
	debugPrint(debugClassName, mScreenName, "default MouseRead");
}

void Screen::MouseTrack(int x, int y)
{
	debugPrint(debugClassName, mScreenName, "default MouseTrack");
}