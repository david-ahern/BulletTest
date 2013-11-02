#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "stdafx.h"

class GameObject;
class Timer;

class ObjectManager
{
private:
	static char* debugClassName;

	std::vector<GameObject*>	mObjectList;

	std::vector<int>			mUpdatedObjects;

public:
	ObjectManager();
	~ObjectManager();

	void			AddObject(GameObject* object);
	bool			RemoveObject(GameObject* object);

	void			ResetList();

	void			InitObjects();

	void			UpdateObjects(int UPDATE_OBJECT_TYPE, float deltaTime);
	void			RenderObjects();

	GameObject*		GetGameObject(char* gameObjectName);
};

#endif