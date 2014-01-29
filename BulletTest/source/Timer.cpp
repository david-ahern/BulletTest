#include "stdafx.h"

char* Timer::debugClassName = "Timer";

Timer::Timer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

Timer::Timer(char* name) : GameObject(name, TIMER_OBJECT)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, name, "constructor");
#endif
}

Timer::~Timer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "destructor");
#endif
}

void Timer::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Init");
#endif

	mPrevTime = GetTickCount();
}

void Timer::Update(float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", BEGIN);
#endif

	mCurTime = GetTickCount();
	mStep = (mCurTime - mPrevTime)/1000;
	mPrevTime = mCurTime;

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mObjectName, "Update", END);
#endif
}