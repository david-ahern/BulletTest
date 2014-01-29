#include "stdafx.h"

char* ObjectManager::debugClassName = "ObjectManager";

// constructor
ObjectManager::ObjectManager()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "constructor");
#endif

	mObjectList.clear();
}

// destructor
ObjectManager::~ObjectManager()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "destructor");
#endif

	for (int i = mObjectList.size()-1; i > 0; --i)
	{
		delete mObjectList.at(i);
	}
}

// push new object onto list and set the objects manager to this.
void ObjectManager::AddObject(GameObject* object)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "AddObject", object->GetObjectName());
#endif

	mObjectList.push_back(object);
	object->SetObjectManager(this);
}

// remove object from this list
bool ObjectManager::RemoveObject(GameObject* object)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "RemoveObject", object->GetObjectName());
#endif

	for (int i = mObjectList.size()-1; i > 0; --i)
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
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "ResetList");
#endif

	mObjectList.clear();
}

// initialise all objects
void ObjectManager::InitObjects()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "InitObjects", BEGIN);
#endif

	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		mObjectList.at(i)->Init();
	}

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "InitObjects", END);
#endif
}

// update objects
void ObjectManager::UpdateObjects(int UPDATE_OBJECT_TYPE, float deltaTime)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "UpdateObjects", UPDATE_OBJECT_TYPE, BEGIN);
#endif

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

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "UpdateObjects", UPDATE_OBJECT_TYPE, END);
#endif
}

// render all objects
void ObjectManager::RenderObjects()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "RenderObjects", BEGIN);
#endif

	// find and place the camera before rendering the rest of the objects.
	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		if (mObjectList.at(i)->GetObjectType() == CAMERA_OBJECT)
			mObjectList.at(i)->Render();
	}

	// render all objects besides the camera
	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		if (mObjectList.at(i)->GetObjectType() != CAMERA_OBJECT)
			mObjectList.at(i)->Render();
	}

#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "RenderObjects", END);
#endif
}

GameObject* ObjectManager::GetGameObject(char* gameObjectName)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "GetGameObject", gameObjectName);
#endif

	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		if (strcmp(mObjectList.at(i)->GetObjectName(), gameObjectName) == 0)
			return mObjectList.at(i);
	}
	return 0;
}

GameObject* ObjectManager::GetGameObject(int OBJ_TYPE)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "GetGameObject", OBJ_TYPE);
#endif

	for (int i = mObjectList.size()-1; i >= 0; --i)
	{
		if (mObjectList.at(i)->GetObjectType() == OBJ_TYPE)
			return mObjectList.at(i);
	}
	return 0;
}