#ifndef _SCREENMANAGER_H_
#define _SCREENMANAGER_H_

#include "stdafx.h"

class ScreenManager
{
private:
	static char* debugClassName;

	ScreenManager();
	ScreenManager(int argc, char** argv);

	ScreenManager(ScreenManager const&);
    void operator=(ScreenManager const&);

	static ScreenManager*	mInstance;

	std::list<Screen*>		mScreenList;

	Screen*					mCurrentScreen;
	Screen*					mNextScreen;

	OGLRenderer*			mRenderer;

public:
	~ScreenManager();

	static ScreenManager*	GetInstance() { return mInstance; }
	static ScreenManager*	GetInstance(int argc, char** argv);

	Screen*					getCurrentScreen() { return mCurrentScreen; }

	void					AddScreen(Screen* newScreen);
	void					RemoveScreen(Screen* screen);
	void					SwitchTo(char* screenName);
	Screen*					GetScreen(char* screenName);

	static void				RenderCallback() { GetInstance()->Render(); }
	static void				UpdateCallback() { GetInstance()->Update(); }

	void					Update();
	void					Render();

	void					MainLoop();
};

extern ScreenManager* systemInstance;

#endif