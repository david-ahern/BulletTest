#ifndef _GAME_H_
#define _GAME_H_

#include "stdafx.h"

class OGLRenderer;
class Timer;
class ObjectManager;

class Game : public Screen
{
private:
	static char* debugClassName;

	bool		exitGame;

	float		mDeltaTime;
	
	GameObject* mPlayerObject;
	Camera*		mCamera;

public:
	Game();
	Game(char* screenName);
	~Game();

	void	ResetGame();

	void	Init();
	void	Update();
	void	Render();

	void	CheckKeyInput();
	void	CheckMouseInput();
};

#endif