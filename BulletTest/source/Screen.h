#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "stdafx.h"

class Screen
{
private:
	static char* debugClassName;

protected:
	char*			mScreenName;
	bool			mIsActive;
	bool			mIsInputActive;
	bool			mIsVisible;

	FileInput*		mFileInput;
	ObjectManager*	mObjectManager;

	cInputHandler*	gInputHandler;

public:
	Screen();
	Screen(char* screenName);
	~Screen();

	ObjectManager*	GetObjectManager()			{ return mObjectManager; }
	char*			GetScreenName()				{ return mScreenName; }
	bool			IsActive()					{ return mIsActive; }
	bool			IsInputActive()				{ return mIsInputActive; }
	bool			IsVisible()					{ return mIsVisible; }
	void			SetActive(bool active)		{ mIsActive = active; }
	void			SetInputActive(bool active)	{ mIsInputActive = active; }
	void			SetVisible(bool visible)	{ mIsVisible = visible; }

	virtual void	Init();
	virtual void	Update();
	virtual void	Render();
	
	virtual void	CheckKeyInput();
	virtual void	CheckMouseInput();
};

#endif