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

	mFileInput->LoadObjects("Screens\\Game.txt");

	mObjectManager->InitObjects();

	debugPrint(debugClassName, mScreenName, "Init", END);
}

void Game::Update()
{
	if(!mIsActive)
		return;

	debugPrint(debugClassName, mScreenName, "Update", BEGIN);

	CheckKeyInput();
	CheckMouseInput();

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
	mObjectManager->UpdateObjects(CRIGIDBODY_OBJECT, mDeltaTime);

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

void Game::CheckKeyInput()
{
	if (!mIsInputActive && !gInputHandler->Keydown())
		return;

	debugPrint(debugClassName, mScreenName, "CheckKeyInput");

	if (gInputHandler->IsDown('w'))
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");
		
		float xrotrad = camera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(sin(yrotrad), -sin(xrotrad), -cos(yrotrad)));
	}
	if (gInputHandler->IsDown('s'))
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");
		
		float xrotrad = camera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(-sin(yrotrad), sin(xrotrad), cos(yrotrad)));
	}
	if (gInputHandler->IsDown('d'))
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(cos(yrotrad), 0, sin(yrotrad)));
	}
	if (gInputHandler->IsDown('a'))
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(-cos(yrotrad), 0, -sin(yrotrad)));
	}
	if (gInputHandler->IsDown('r'))
	{
		this->Init();
		gInputHandler->KeyboardUp('r', 0, 0);
	}
	if (gInputHandler->IsDown(' '))
	{
		cSphere* sphere = new cSphere("bulletBody");
		mObjectManager->AddObject(sphere);
		sphere->Create(1);

		cRigidBody* bullet = new cRigidBody("bullet");
		mObjectManager->AddObject(bullet);
		bullet->Create("bulletBody", Vector3(10, 8, 15),
										Vector3(0,0,0),
										2);

		bullet->SetVelocity(Vector3(-10, 0, -20));
	}
}

void Game::CheckMouseInput()
{
	if(!mIsInputActive && gInputHandler->MouseDown() == NO_MOUSE)
		return;

	debugPrint(debugClassName, mScreenName, "default CheckMouseInput");

	if (gInputHandler->MouseDown() == LEFT_MOUSE)
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		Vector2 mouseTrack = gInputHandler->GetMouseTrack();

		camera->ApplyRotation(Vector3((mouseTrack.y)/8, (mouseTrack.x)/8, 0));
	}
}