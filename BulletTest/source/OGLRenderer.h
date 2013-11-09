#ifndef _OGLRENDERER_H_
#define _OGLRENDERER_H_

#include "stdafx.h"

class ScreenManager;

class OGLRenderer
{
private:
	static char* debugClassName;
public:
	OGLRenderer();
	OGLRenderer(int argc, char **argv);
	~OGLRenderer();

	void		SetIdleFunc(void idleFunc());
	void		SetDisplayFunc(void renderFunc());
	void		SetKeyboardDownFunc(void keyboardDownFunc(unsigned char key, int x, int y));
	void		SetKeyboardUpFunc(void keyboardUpFunc(unsigned char key, int x, int y));
	void		SetMouseReadFunc(void mouseReadFunc(int button, int state, int x, int y));
	void		SetMouseTrackFunc(void mouseTrackFunc(int x, int y));

	void		Init();

	void		PrepareRendering();

	void		FinishRendering();

	static void Reshape(int w, int h);
};

#endif