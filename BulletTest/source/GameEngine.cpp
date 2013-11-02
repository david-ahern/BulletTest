#include "stdafx.h"

char* GameEngine::debugClassName = "GameEngine";

GameEngine* GameEngine::mInstance = 0;

GameEngine::GameEngine()
{
	debugPrint(debugClassName, "constructor");
}

GameEngine::~GameEngine()
{
	debugPrint(debugClassName, "destructor");
}

GameEngine* GameEngine::GetInstance()
{
	debugPrint(debugClassName, "GetInstance");
	if(!mInstance)
		mInstance = new GameEngine;

	return mInstance;
}

void GameEngine::Init(int argc, char** argv)
{
	debugPrint(debugClassName, "Init");

	mScreenList.clear();

	mRenderer = new OGLRenderer(argc, argv);

	mRenderer->SetDisplayFunc(RenderCallback);
	mRenderer->SetIdleFunc(UpdateCallback);
	
	mRenderer->Init();

	mCurrentScreen = 0;
	mNextScreen = 0;
}

void GameEngine::AddScreen(Screen* screen)
{
	debugPrint(debugClassName, "AddScreen");

	mScreenList.push_back(screen);
}

void GameEngine::RemoveScreen(Screen* screen)
{
	debugPrint(debugClassName, "RemoveScreen");

	mScreenList.remove(screen);
}

void GameEngine::SwitchTo(char* newScreen)
{
	debugPrint(debugClassName, "SwitchTo", newScreen);

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
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
		mCurrentScreen->SetVisible(true);
		mNextScreen = 0;
	}
	else
	{
		mNextScreen->SetActive(true);
		mNextScreen->SetInputActive(true);
		mNextScreen->SetVisible(true);

		mCurrentScreen->SetInputActive(false);
		mCurrentScreen->SetActive(false);
		mCurrentScreen->SetVisible(false);

		mCurrentScreen = mNextScreen;

		mNextScreen = 0;
	}
}

Screen* GameEngine::GetScreen(char* name)
{
	debugPrint(debugClassName, "GetScreen", name);

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
	{
		if ((*sc)->GetScreenName() == name)
			return *sc;
	}
	return 0;
}

void GameEngine::UpdateCallback()
{
	GameEngine::GetInstance()->Update();
}

void GameEngine::RenderCallback()
{
	GameEngine::GetInstance()->Render();
}

void GameEngine::Update()
{
	debugPrint(debugClassName, "Update", BEGIN);

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Update();

	debugPrint(debugClassName, "Update", END);

	glutPostRedisplay();
}

void GameEngine::Render()
{
	debugPrint(debugClassName, "Render", BEGIN);

	mRenderer->PrepareRendering();

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Render();

	mRenderer->FinishRendering();

	debugPrint(debugClassName, "Render", END);
}

void GameEngine::MainLoop()
{
	debugPrint(debugClassName, "MainLoop");
	glutMainLoop();
}