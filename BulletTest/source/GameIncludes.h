#ifndef _GAMEINCLUDES_H_
#define _GAMEINCLUDES_H_

//Includes
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix44.h"
#include "FileInput.h"
#include "OGLRenderer.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "Screen.h"
#include "GameEngine.h"
#include "Game.h"
#include "Timer.h"
#include "Light.h"
#include "Camera.h"
#include "BulletCollisionShape.h"
#include "BulletWorld.h"
#include "BulletRigidBody.h"
#include "CameraThirdPerson.h"
#include "CameraFree.h"
//insertNewIncludeHere

//ObjectTypes
#define NO_OBJECT_TYPE 0
#define ALL_OBJECTS 1
#define BULLETWORLD_OBJECT 2
#define BULLETCOLLISIONSHAPE_OBJECT 3
#define BULLETRIGIDBODY_OBJECT 4
#define CAMERA_OBJECT 5
#define LIGHT_OBJECT 6
#define TIMER_OBJECT 7
#define CAMERATHIRDPERSON_OBJECT 8
#define CAMERAFREE_OBJECT 9
//insertNewObjectTypeHere

#endif
