#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_
//Description: Manager for all GameObjects in a Screen

#include "stdafx.h"

class GameObject;
class Timer;

class ObjectManager
{
private:
	static char* debugClassName;

	// list of objects
	std::vector<GameObject*>	mObjectList;

	// list of object types already updated
	std::vector<int>			mUpdatedObjects;

public:
	ObjectManager();
	~ObjectManager();

	// add and removed objects from list
	void			AddObject(GameObject* object);
	bool			RemoveObject(GameObject* object);

	// clear list
	void			ResetList();

	// call all objects init functions
	void			InitObjects();

	// call every objects update func
	void			UpdateObjects(int UPDATE_OBJECT_TYPE, float deltaTime);
	// call every objects render func
	void			RenderObjects();

	// returns game object
	GameObject*		GetGameObject(char* gameObjectName);
};

#endif