#include "stdafx.h"

char* GameEngine::debugClassName = "GameEngine";

GameEngine* GameEngine::mInstance = 0;

GameEngine::GameEngine()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "constructor");
#endif
}

GameEngine::~GameEngine()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "destructor");
#endif
}

GameEngine* GameEngine::GetInstance()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "GetInstance");
#endif

	if(!mInstance)
		mInstance = new GameEngine;

	return mInstance;
}

void GameEngine::Init(int argc, char** argv)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Init");
#endif

	mScreenList.clear();

	mRenderer = new OGLRenderer(argc, argv);

	mRenderer->SetDisplayFunc(RenderCallback);
	mRenderer->SetIdleFunc(UpdateCallback);

	mRenderer->SetKeyboardDownFunc(KeyboardDownCallback);
	mRenderer->SetKeyboardUpFunc(KeyboardUpCallback);
	mRenderer->SetMouseReadFunc(MouseReadCallback);
	mRenderer->SetMouseTrackFunc(MouseTrackCallback);
	
	mRenderer->Init();

	mCurrentScreen = 0;
	mNextScreen = 0;

	mInputHandler = new cInputHandler();

	mInputHandler->Init();
}

void GameEngine::AddScreen(Screen* screen)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "AddScreen");
#endif

	mScreenList.push_back(screen);
}

void GameEngine::RemoveScreen(Screen* screen)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "RemoveScreen");
#endif

	mScreenList.remove(screen);
}

void GameEngine::SwitchTo(char* newScreen)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SwitchTo", newScreen);
#endif

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
	{
		if ((*sc)->GetScreenName() == newScreen)
			mNextScreen = *sc;
	}

	if (mNextScreen == 0)
	{
#if defined(DEBUG_OUTPUT)
		debugPrint("screen not found");
#endif
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
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "GetScreen", name);
#endif

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

void GameEngine::KeyboardDownCallback(unsigned char key, int x, int y)
{
	GameEngine::GetInstance()->mInputHandler->KeyboardDown(key, x, y);
}

void GameEngine::KeyboardUpCallback(unsigned char key, int x, int y)
{
	GameEngine::GetInstance()->mInputHandler->KeyboardUp(key, x, y);
}

void GameEngine::MouseReadCallback(int button, int state, int x, int y)
{
	GameEngine::GetInstance()->mInputHandler->MouseRead(button, state, x, y);
}

void GameEngine::MouseTrackCallback(int x, int y)
{
	GameEngine::GetInstance()->mInputHandler->MouseTrack(x, y);
}

void GameEngine::Update()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Update", BEGIN);
#endif

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Update();

	glutPostRedisplay();

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Update", END);
#endif
}

void GameEngine::Render()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Render", BEGIN);
#endif

	mRenderer->PrepareRendering();

	for (std::list<Screen*>::iterator sc = mScreenList.begin(); sc != mScreenList.end(); ++sc)
		(*sc)->Render();

	mRenderer->FinishRendering();

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Render", END);
#endif
}

void GameEngine::MainLoop()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "MainLoop");
#endif

	glutMainLoop();
}