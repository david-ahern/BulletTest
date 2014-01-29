#include "stdafx.h"

char* Game::debugClassName = "Game";

Game::Game()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

Game::Game(char* name) : Screen(name)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "constructor");
#endif
}

Game::~Game()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "destructor");
#endif

	delete mFileInput;
	delete mObjectManager;
}


void Game::ResetGame()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "ResetGame");
#endif

	delete mFileInput;
	delete mObjectManager;
}

void Game::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Init", BEGIN);
#endif
	
	exitGame = false;

	mObjectManager = new ObjectManager();

	mFileInput = new FileInput(mObjectManager);
	mFileInput->LoadObjects("Screens\\Game.txt");

	mObjectManager->InitObjects();

	mCamera = (Camera*)mObjectManager->GetGameObject("camera");

	mPlayerObject = mObjectManager->GetGameObject("player");

	if(mPlayerObject)
	{
		mCamera->SetTarget(mPlayerObject);
		mCamera->SetCameraMode(THIRDPERSON_CAMERA);
	}

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Init", END);
#endif
}

void Game::Update()
{
	if(!mIsActive)
		return;

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Update", BEGIN);
#endif

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

	mObjectManager->UpdateObjects(CPLAYER_OBJECT, mDeltaTime);

	mObjectManager->UpdateObjects(CAMERA_OBJECT, mDeltaTime);

	//mObjectManager->UpdateObjects(ALL_OBJECTS, mDeltaTime);

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Update", END);
#endif
}

void Game::Render()
{
	if(!mIsVisible)
		return;
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Render", BEGIN);
#endif

	mObjectManager->RenderObjects();

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "Render", END);
#endif
}

void Game::CheckKeyInput()
{
	if ((!mIsInputActive) || (!gInputHandler->Keydown()))
		return;

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "CheckKeyInput");
#endif

	float mMovementForce = ((cPlayer*)mPlayerObject)->GetMovementForce();

	if (gInputHandler->IsDown(MOVE_FORWARD_CONTROL))
	{		
		float xrotrad = mCamera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(sin(yrotrad), -sin(xrotrad), -cos(yrotrad)));
		else
		{
			((cPlayer*)mPlayerObject)->GetRigidBody()->ApplyForce(Vector3(sin(yrotrad) * mMovementForce, 0, -cos(yrotrad) * mMovementForce));
		}
	}
	else
		((cPlayer*)mPlayerObject)->DisableMovement(MOVE_FORWARD);

	if (gInputHandler->IsDown(MOVE_BACKWARD_CONTROL))
	{		
		float xrotrad = mCamera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)

			mCamera->ApplyPosition(Vector3(-sin(yrotrad), sin(xrotrad), cos(yrotrad)));
		else
		{
			((cPlayer*)mPlayerObject)->GetRigidBody()->ApplyForce(Vector3(-sin(yrotrad) * mMovementForce, 0, cos(yrotrad) * mMovementForce));
		}
	}
	else
		((cPlayer*)mPlayerObject)->DisableMovement(MOVE_BACKWARD);


	if (gInputHandler->IsDown(MOVE_RIGHT_CONTROL))
	{
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(cos(yrotrad), 0, sin(yrotrad)));
		else
		{
			((cPlayer*)mPlayerObject)->GetRigidBody()->ApplyForce(Vector3(cos(yrotrad) * mMovementForce, 0, sin(yrotrad) * mMovementForce));
		}
	}
	else
		((cPlayer*)mPlayerObject)->DisableMovement(MOVE_RIGHT);

	if (gInputHandler->IsDown(MOVE_LEFT_CONTROL))
	{
		float yrotrad = mCamera->GetRotation().y * DEG_TO_RAD;

		if (mCamera->GetCameraMode() != THIRDPERSON_CAMERA)
			mCamera->ApplyPosition(Vector3(-cos(yrotrad), 0, -sin(yrotrad)));
		else
		{
			((cPlayer*)mPlayerObject)->GetRigidBody()->ApplyForce(Vector3(-cos(yrotrad) * mMovementForce, 0, -sin(yrotrad) * mMovementForce));
		}
	}
	else
		((cPlayer*)mPlayerObject)->DisableMovement(MOVE_LEFT);

	if (gInputHandler->IsDown(RESET_CONTROL))
	{
		gInputHandler->KeyboardUp('r', 0, 0);
		ResetGame();
		Init();
	}
	if (gInputHandler->IsDown(JUMP_CONTROL))
	{
		gInputHandler->KeyboardUp(' ', 0, 0);

		ObjectData data = GetDefaultDataValues();
		data.nRadius = 1;

		cSphere* sphere = new cSphere("bulletBody");
		mObjectManager->AddObject(sphere);
		sphere->Create(data);

		data.nCollisionShapeName = "bulletBody";
		data.nPosition = Vector3(10, 5, 15);
		data.nRotation = Vector3(0, 0, 0);
		data.nMass = 20;

		cRigidBody* bullet = new cRigidBody("bullet");
		mObjectManager->AddObject(bullet);
		bullet->Create(data);

		bullet->SetVelocity(Vector3(-10, 0, -20));
	}
	if(gInputHandler->IsDown(CHANGE_CAMERA_CONTROL))
	{
		if (mCamera->GetCameraMode() == THIRDPERSON_CAMERA)
		{
			((cPlayer*)mPlayerObject)->GetRigidBody()->SetActive(true);
			((cPlayer*)mPlayerObject)->GetRigidBody()->ApplyForce(Vector3(0, 100, 0));
		}
	}
}

void Game::CheckMouseInput()
{
	if(!mIsInputActive || gInputHandler->MouseDown() == NO_MOUSE)
		return;

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, mScreenName, "default CheckMouseInput");
#endif

	if (gInputHandler->MouseDown() == LEFT_MOUSE)
	{
		Camera* camera = (Camera*)mObjectManager->GetGameObject("camera");

		Vector2 mouseTrack = gInputHandler->GetMouseTrack(true);

		camera->ApplyRotation(Vector3((mouseTrack.y)/8, (mouseTrack.x)/8, 0));
	}
}