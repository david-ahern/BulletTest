#ifndef _CINPUTHANDLER_H_
#define _CINPUTHANDLER_H_

// Created by: David
// Handler for keypresses and mouse input.

#include "stdafx.h"

#define NO_MOUSE		0
#define LEFT_MOUSE		1
#define MIDDLE_MOUSE	2
#define RIGHT_MOUSE		3

class cInputHandler
{
private:
	static char* debugClassName;

	std::map< unsigned char, bool > state;
	bool			mKeypressed;

	int				mMouseDown;
	Vector2			mMousePos;
	Vector2			mMouseTrack;

public:
	cInputHandler();
	~cInputHandler();

	void		KeyboardDown(unsigned char key, int x, int y);
	void		KeyboardUp(unsigned char key, int x, int y);
	void		MouseRead(int button, int state, int x, int y);
	void		MouseTrack(int x, int y);

	bool		Keydown()		{ return mKeypressed; }
	bool		IsDown(unsigned char key);

	int			MouseDown()		{ return mMouseDown; }
	Vector2		GetMousePos()	{ return mMousePos; }
	Vector2		GetMouseTrack(bool clearTrack);

	void		Init();
};

#endif
