#ifndef _TIMER_H_
#define _TIMER_H_

#include "stdafx.h"

class GameObject;

class Timer : public GameObject
{
private:
	static char* debugClassName;

	double	mCurTime;
	double	mPrevTime;

	double	mStep;

public:
	Timer(void);
	Timer(char* objectName);
	~Timer();

	double	GetStep(void) { return mStep; }
	double	GetTime(void) { return GetTickCount(); }

	void	Init();
	void	Update(float deltaTime);
};

#endif