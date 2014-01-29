#include "stdafx.h"

char* Screen::debugClassName = "Screen";

Screen::Screen()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty base constructor");
#endif
}

Screen::Screen(char* name)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, name, "base constructor");
#endif

	mScreenName = name;

	mIsActive = false;
	mIsInputActive = false;
	mIsVisible = false;

	gInputHandler = GameEngine::GetInstance()->GetInputHandler();
}

Screen::~Screen()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "base destructor");
#endif
}

void Screen::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default Init");
#endif
}

void Screen::Update()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default Update");
#endif
}

void Screen::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default Render");
#endif
}

void Screen::CheckKeyInput()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default CheckKeyInput");
#endif
}

void Screen::CheckMouseInput()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default CheckMouseInput");
#endif
}