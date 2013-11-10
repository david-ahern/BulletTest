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

	mPlayerObject = mObjectManager->GetGameObject("player");

	mCamera = (Camera*)mObjectManager->GetGameObject("camera");

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

	mObjectManager->UpdateObjects(CAMERA_OBJECT, mDeltaTime);

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
	if ((!mIsInputActive) || (!gInputHandler->Keydown()))
		return;

	debugPrint(debugClassName, mScreenName, "CheckKeyInput");

	if (gInputHandler->IsDown('w'))
	{		
		float xrotrad = mCamera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(sin(yrotrad), -sin(xrotrad), -cos(yrotrad)));
		else
		{
			((cRigidBody*)mPlayerObject)->SetActive(true);
			((cRigidBody*)mPlayerObject)->ApplyForce(Vector3(sin(yrotrad) * 100, 0, -cos(yrotrad) * 100));
		}
	}
	if (gInputHandler->IsDown('s'))
	{		
		float xrotrad = mCamera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)

			mCamera->ApplyPosition(Vector3(-sin(yrotrad), sin(xrotrad), cos(yrotrad)));
		else
		{
			((cRigidBody*)mPlayerObject)->SetActive(true);
			((cRigidBody*)mPlayerObject)->ApplyForce(Vector3(-sin(yrotrad) * 100, 0, cos(yrotrad) * 100));
		}
	}
	if (gInputHandler->IsDown('d'))
	{
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(cos(yrotrad), 0, sin(yrotrad)));
		else
		{
			((cRigidBody*)mPlayerObject)->SetActive(true);
			((cRigidBody*)mPlayerObject)->ApplyForce(Vector3(cos(yrotrad) * 100, 0, sin(yrotrad) * 100));
		}
	}
	if (gInputHandler->IsDown('a'))
	{
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(-cos(yrotrad), 0, -sin(yrotrad)));
		else
		{
			((cRigidBody*)mPlayerObject)->SetActive(true);
			((cRigidBody*)mPlayerObject)->ApplyForce(Vector3(-cos(yrotrad) * 100, 0, -sin(yrotrad) * 100));
		}
	}
	if (gInputHandler->IsDown('r'))
	{
		this->Init();
		gInputHandler->KeyboardUp('r', 0, 0);
	}
	if (gInputHandler->IsDown(' '))
	{
		gInputHandler->KeyboardUp(' ', 0, 0);

		ObjectData data;
		data.nRadius = 1;

		cSphere* sphere = new cSphere("bulletBody");
		mObjectManager->AddObject(sphere);
		sphere->Create(data);

		data.nCollisionShapeName = "bulletBody";
		data.nPosition = Vector3(10, 5, 15);
		data.nRotation = Vector3(0, 0, 0);
		data.nMass = 2;

		cRigidBody* bullet = new cRigidBody("bullet");
		mObjectManager->AddObject(bullet);
		bullet->Create(data);

		bullet->SetVelocity(Vector3(-10, 0, -20));

		mPlayerObject = bullet;

		mCamera->SetCameraMode(THIRDPERSON_CAMERA);
		mCamera->SetTarget(mPlayerObject);
	}
}

void Game::CheckMouseInput()
{
	if(!mIsInputActive || gInputHandler->MouseDown() == NO_MOUSE)
		return;

	debugPrint(debugClassName, mScreenName, "default CheckMouseInput");

	if (gInputHandler->MouseDown() == LEFT_MOUSE)
	{
		Camera* camera = (Camera*)mObjectManager->GetGameObject("camera");

		Vector2 mouseTrack = gInputHandler->GetMouseTrack(true);

		camera->ApplyRotation(Vector3((mouseTrack.y)/8, (mouseTrack.x)/8, 0));
	}
}