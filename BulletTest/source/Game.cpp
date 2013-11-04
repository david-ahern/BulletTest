#include "stdafx.h"

char* Game::debugClassName = "Game";

Game::Game()
{
	debugPrint(debugClassName, "empty constructor");
}

Game::Game(char* name) : Screen(name)
{
	debugPrint(debugClassName, mScreenName, "constructor");

	exitGame = false;
}

Game::~Game()
{
	debugPrint(debugClassName, mScreenName, "destructor");

	delete mFileInput;
	delete mObjectManager;
}

void Game::Init()
{
	debugPrint(debugClassName, mScreenName, "Init", BEGIN);

	mObjectManager = new ObjectManager();

	mFileInput = new FileInput(mObjectManager);

	mFileInput->LoadObjects("USE DEFAULT INIT.txt");

	mObjectManager->InitObjects();

	debugPrint(debugClassName, mScreenName, "Init", END);
}

void Game::Update()
{
	if(!mIsActive)
		return;

	debugPrint(debugClassName, mScreenName, "Update", BEGIN);

	//update timer
	mObjectManager->UpdateObjects(TIMER_OBJECT, 0);

	//get timer and set delta time value
	Timer* timer = (Timer*)mObjectManager->GetGameObject("gameTimer");
	if (timer != NULL)
		mDeltaTime = timer->GetStep();
	else
		mDeltaTime = 0;

	//update bullet world
	mObjectManager->UpdateObjects(BULLETWORLD_OBJECT, mDeltaTime);
	mObjectManager->UpdateObjects(BULLETRIGIDBODY_OBJECT, mDeltaTime);

	mObjectManager->UpdateObjects(ALL_OBJECTS, mDeltaTime);

	debugPrint(debugClassName, mScreenName, "Update", END);
}

void Game::Render()
{
	if(!mIsVisible)
		return;

	debugPrint(debugClassName, mScreenName, "Render", BEGIN);

	mObjectManager->RenderObjects();

	debugPrint(debugClassName, mScreenName, "Render", END);
}

void Game::KeyboardRead(unsigned char key, int x, int y)
{
	if (!mIsInputActive)
		return;

	debugPrint(debugClassName, mScreenName, "KeyboardRead");

}

void Game::MouseRead(int button, int state, int x, int y)
{
	if (!mIsInputActive)
		return;

	debugPrint(debugClassName, mScreenName, "MouseRead");

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseRot = true;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseX = x;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseY = y;
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseRot = false;
    }
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseMove = true;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseX = x;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseY = y;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseMove = false;
	}
}

void Game::MouseTrack(int x, int y)
{
	if (!mIsInputActive)
		return;

	debugPrint(debugClassName, mScreenName, "MouseTrack");

	if (((Camera*)mObjectManager->GetGameObject("camera"))->mouseRot)
	{
		((Camera*)mObjectManager->GetGameObject("camera"))->rotateY(((float)x - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseX)/4);
		((Camera*)mObjectManager->GetGameObject("camera"))->rotateX(((float)y - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseY)/4);
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseX = x;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseY = y;
	}
	else if (((Camera*)mObjectManager->GetGameObject("camera"))->mouseMove)
	{
		((Camera*)mObjectManager->GetGameObject("camera"))->updatePos(((float)x - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseX)/4,((float)y - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseY)/4);
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseX = x;
		((Camera*)mObjectManager->GetGameObject("camera"))->mouseY = y;
	}
}