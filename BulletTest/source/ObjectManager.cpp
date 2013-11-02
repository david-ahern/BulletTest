#include "stdafx.h"

char* ObjectManager::debugClassName = "ObjectManager";

// constructor
ObjectManager::ObjectManager()
{
	debugPrint(debugClassName, "constructor");
	mObjectList.clear();
}

// destructor
ObjectManager::~ObjectManager()
{
	debugPrint(debugClassName, "destructor");
}

// push new object onto list and set the objects manager to this.
void ObjectManager::AddObject(GameObject* object)
{
	debugPrint(debugClassName, "AddObject", object->GetObjectName());
	mObjectList.push_back(object);
	object->SetObjectManager(this);
}

// remove object from this list
bool ObjectManager::RemoveObject(GameObject* object)
{
	debugPrint(debugClassName, "RemoveObject", object->GetObjectName());
	for (int i = mObjectList.size(); i > 0; --i)
	{
		if (object == mObjectList.at(i))
		{
			mObjectList.erase(mObjectList.begin() + i);
			return true;
		}
	}
	return false;
}

// clear list
void ObjectManager::ResetList()
{
	debugPrint(debugClassName, "ResetList");
	mObjectList.clear();
}

// initialise all objects
void ObjectManager::InitObjects()
{
	debugPrint(debugClassName, "InitObjects", BEGIN);
	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		mObjectList.at(i)->Init();
	}
	debugPrint(debugClassName, "InitObjects", END);
}

// update objects
void ObjectManager::UpdateObjects(int UPDATE_OBJECT_TYPE, float deltaTime)
{
	debugPrint(debugClassName, "UpdateObjects", UPDATE_OBJECT_TYPE, BEGIN);
	// update all not updated objects
	if (UPDATE_OBJECT_TYPE == ALL_OBJECTS)
	{
		bool doNotUpdate;
		for (int i = mObjectList.size()-1; i >= 0; --i)
		{
			doNotUpdate = false;
			for (int j = mUpdatedObjects.size()-1; j >= 0; --j)
			{
				// if object has been updated set dont update flag
				if (mObjectList.at(i)->GetObjectType() == mUpdatedObjects.at(j))
					doNotUpdate = true;
			}

			if (!doNotUpdate)
				mObjectList.at(i)->Update(deltaTime);
		}
		//clear updated objects list
		mUpdatedObjects.clear();
	}
	else
	{	// update all objects matching the update_object_type
		for (int i = mObjectList.size()-1; i >= 0; --i)
		{
			if (mObjectList.at(i)->GetObjectType() == UPDATE_OBJECT_TYPE)
				mObjectList.at(i)->Update(deltaTime);
		}
		mUpdatedObjects.push_back(UPDATE_OBJECT_TYPE);
	}

	debugPrint(debugClassName, "UpdateObjects", UPDATE_OBJECT_TYPE, END);
}

// render all objects
void ObjectManager::RenderObjects()
{
	debugPrint(debugClassName, "RenderObjects", BEGIN);

	// get camera and perform camera transform before starting
	Camera* camera = (Camera*)GetGameObject("camera");
	camera->place();

	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		mObjectList.at(i)->Render();
	}

	debugPrint(debugClassName, "RenderObjects", END);
}

GameObject* ObjectManager::GetGameObject(char* gameObjectName)
{
	debugPrint(debugClassName, "GetGameObject", gameObjectName);

	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		if (mObjectList.at(i)->GetObjectName() == gameObjectName)
			return mObjectList.at(i);
	}
	return 0;
}