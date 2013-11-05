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

	bool	exitGame;

	float	mDeltaTime;

	bool	mMouseClicked;
	int		mMouseButton;
	Vector3	mMousePosition;

public:
	Game();
	Game(char* screenName);
	~Game();

	void	Init();
	void	Update();
	void	Render();

	void	KeyboardRead(unsigned char key, int x, int y);
	void	MouseRead(int button, int state, int x, int y);
	void	MouseTrack(int x, int y);
};

#endif