#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "stdafx.h"

class GameEngine
{
private:
	static char* debugClassName;
	
	static GameEngine*	mInstance;

	OGLRenderer*		mRenderer;

	std::list<Screen*>	mScreenList;

	Screen*				mCurrentScreen;
	Screen*				mNextScreen;


	GameEngine();

	GameEngine(GameEngine const&);
	void operator=(GameEngine const&);

public:
	~GameEngine();
	
	static		GameEngine* GetInstance();

	void		Init(int argc, char** argv);

	Screen*		GetCurrentScree() { return mCurrentScreen; }

	void		AddScreen(Screen* screen);
	void		RemoveScreen(Screen* screen);
	void		SwitchTo(char* screenName);
	Screen*		GetScreen(char* screenName);

	static void	UpdateCallback();
	static void RenderCallback();

	void		Update();
	void		Render();

	void		MainLoop();
};

extern GameEngine* GameEngineInstance;

#endif