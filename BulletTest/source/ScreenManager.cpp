#include "stdafx.h"

char* ScreenManager::debugClassName = "ScreenManager";


static ScreenManager* systemInstance = ScreenManager::GetInstance();
ScreenManager* ScreenManager::mInstance = systemInstance;

ScreenManager::ScreenManager()
{
	debugPrint(debugClassName, "empty constructor");
}

ScreenManager::ScreenManager(int argc, char **argv)
{
	debugPrint(debugClassName, "constructor");

	mScreenList.clear();

	mRenderer = new OGLRenderer(argc, argv);

	mRenderer->SetDisplayFunc(RenderCallback);
	mRenderer->SetIdleFunc(UpdateCallback);

	mRenderer->Init();

	mCurrentScreen = 0;
	mNextScreen = 0;

	mInstance = this;
}

ScreenManager::~ScreenManager()
{
	debugPrint(debugClassName, "descructor");

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		delete *sc;
}

void ScreenManager::AddScreen(Screen* screen)
{
	debugPrint(debugClassName, "AddScreen");

	mScreenList.push_back(screen);
}

void ScreenManager::RemoveScreen(Screen* screen)
{
	debugPrint(debugClassName, "RemoveScreen");

	mScreenList.remove(screen);
}

Screen* ScreenManager::GetScreen(char* name)
{
	debugPrint(debugClassName, "GetScreen");

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
	{
		if ((*sc)->GetScreenName() == name)
			return *sc;
	}
	return 0;
}

void ScreenManager::SwitchTo(char* newScreen)
{
	debugPrint(debugClassName, "SwitchTo");

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.begin(); ++sc)
	{
		if ((*sc)->GetScreenName() == newScreen)
			mNextScreen = *sc;
	}

	if (mNextScreen == 0)
	{
		debugPrint("screen not found");
		return;
	}
	if (mCurrentScreen == 0)
	{
		mCurrentScreen = mNextScreen;
		mCurrentScreen->SetActive(true);
		mCurrentScreen->SetInputActive(true);
		mNextScreen = 0;
	}
	else
	{
		mNextScreen->SetActive(true);
		mNextScreen->SetInputActive(true);

		mCurrentScreen->SetInputActive(false);
		mCurrentScreen->SetActive(false);
		mCurrentScreen = mNextScreen;

		mNextScreen = 0;
	}
}

void ScreenManager::Update()
{
	debugPrint(debugClassName, "Update", BEGIN);

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Update();

	debugPrint(debugClassName, "Update", END);
}

void ScreenManager::Render()
{
	debugPrint(debugClassName, "Render", BEGIN);

	mRenderer->PrepareRendering();

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Render();

	mRenderer->FinishRendering();

	debugPrint(debugClassName, "Render", END);
}

void ScreenManager::MainLoop()
{
	debugPrint(debugClassName, "MainLoop");
	glutMainLoop();
}

ScreenManager* ScreenManager::GetInstance(int argc, char** argv)
{
	mInstance = new ScreenManager(argc, argv);
	return mInstance;
}