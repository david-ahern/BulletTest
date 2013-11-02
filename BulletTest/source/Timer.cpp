#include "stdafx.h"

char* Timer::debugClassName = "Timer";

Timer::Timer()
{
	debugPrint(debugClassName, "empty constructor");
}

Timer::Timer(char* name) : GameObject(name, TIMER_OBJECT)
{
	debugPrint(debugClassName, name, "constructor");
}

Timer::~Timer()
{
	debugPrint(debugClassName, mObjectName, "destructor");
}

void Timer::Init()
{
	debugPrint(debugClassName, mObjectName, "Init");
	mPrevTime = GetTickCount();
}

void Timer::Update(float deltaTime)
{
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);

	mCurTime = GetTickCount();
	mStep = (mCurTime - mPrevTime)/1000;
	mPrevTime = mCurTime;

	debugPrint(debugClassName, mObjectName, "Update", END);
}