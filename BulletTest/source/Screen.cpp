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

	gInputHandler = GameEngine::GetInstance()->GetInputHandler();
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

void Screen::CheckKeyInput()
{
	debugPrint(debugClassName, mScreenName, "default CheckKeyInput");
}

void Screen::CheckMouseInput()
{
	debugPrint(debugClassName, mScreenName, "default CheckMouseInput");
}