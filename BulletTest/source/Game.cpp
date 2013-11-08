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

void Game::KeyboardRead(unsigned char key, int x, int y)
{
	if (!mIsInputActive)
		return;

	debugPrint(debugClassName, mScreenName, "KeyboardRead");

	//move forward
	if (key == 'w')
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");
		
		float xrotrad = camera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(sin(yrotrad), -sin(xrotrad), -cos(yrotrad)));
	}
	// move back
	if (key == 's')
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");
		
		float xrotrad = camera->GetRotation().x * DEG_TO_RAD;
		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(-sin(yrotrad), sin(xrotrad), cos(yrotrad)));
	}
	// move right
	if (key == 'd')
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(cos(yrotrad), 0, sin(yrotrad)));
	}
	if (key == 'a')
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		float yrotrad = camera->GetRotation().y * DEG_TO_RAD;

		camera->ApplyPosition(Vector3(-cos(yrotrad), 0, -sin(yrotrad)));
	}
	if (key == 'r')
	{
		this->Init();
	}
	if (key == ' ')
	{
		cSphere* sphere = new cSphere("bulletBody");
		mObjectManager->AddObject(sphere);
		sphere->Create(1);

		cRigidBody* bullet = new cRigidBody("bullet");
		mObjectManager->AddObject(bullet);
		bullet->Create("bulletBody", Vector3(10, 8, -10),
										Vector3(0,0,0),
										2);

		bullet->SetVelocity(Vector3(-10, 0, 10));
	}
}

void Game::MouseRead(int button, int state, int x, int y)
{
	if (!mIsInputActive)
		return;

	debugPrint(debugClassName, mScreenName, "MouseRead");

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		mMouseClicked = true;
		mMouseButton = GLUT_LEFT_BUTTON;
		mMousePosition.x = x;
		mMousePosition.y = y;
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
		mMouseClicked = false;
		mMouseButton = -1;
    }
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		mMouseClicked = true;
		mMouseButton = GLUT_RIGHT_BUTTON;
		mMousePosition.x = x;
		mMousePosition.y = y;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		mMouseClicked = false;
		mMouseButton = -1;
	}
}

void Game::MouseTrack(int x, int y)
{
	if (!mIsInputActive)
		return;
	
	debugPrint(debugClassName, mScreenName, "MouseTrack");

	if ((mMouseClicked) && (mMouseButton == GLUT_LEFT_BUTTON))
	{
		CameraFree* camera = (CameraFree*)mObjectManager->GetGameObject("camera");

		camera->ApplyRotation(Vector3((y - mMousePosition.y)/8, (x - mMousePosition.x)/8, 0));
		mMousePosition.x = x;
		mMousePosition.y = y;
	}
	//else if (((Camera*)mObjectManager->GetGameObject("camera"))->mouseMove)
	//{
	//	((Camera*)mObjectManager->GetGameObject("camera"))->updatePos(((float)x - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseX)/4,((float)y - ((Camera*)mObjectManager->GetGameObject("camera"))->mouseY)/4);
	//	((Camera*)mObjectManager->GetGameObject("camera"))->mouseX = x;
	//	((Camera*)mObjectManager->GetGameObject("camera"))->mouseY = y;
	//}
}