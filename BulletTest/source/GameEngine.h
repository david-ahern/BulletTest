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

	Screen*		GetCurrentScree() { return mCurrentScreen; }

	void		AddScreen(Screen* screen);
	void		RemoveScreen(Screen* screen);
	void		SwitchTo(char* screenName);
	Screen*		GetScreen(char* screenName);

	static void	UpdateCallback();
	static void RenderCallback();
	static void KeyboardReadCallback(unsigned char key, int x, int y);
	static void MouseReadCallback(int button, int state, int x, int y);
	static void MouseTrackCallback(int x, int y);

	void		Init(int argc, char** argv);
	void		Update();
	void		Render();

	void		KeyboardRead(unsigned char key, int x, int y);
	void		MouseRead(int button, int state, int x, int y);
	void		MouseTrack(int x, int y);

	void		MainLoop();
};

extern GameEngine* GameEngineInstance;

#endif