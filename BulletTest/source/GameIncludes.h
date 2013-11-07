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
#include "iCollisionShape.h"
#include "Screen.h"
#include "GameEngine.h"
#include "Game.h"
#include "Timer.h"
#include "Light.h"
#include "Camera.h"
#include "BulletWorld.h"
#include "CameraThirdPerson.h"
#include "CameraFree.h"
#include "cSphere.h"
#include "cBox.h"
#include "cCylinder.h"
#include "cCapsule.h"
#include "cCone.h"
#include "cStaticPlane.h"
#include "cRigidBody.h"
//insertNewIncludeHere

//ObjectTypes
#define NO_OBJECT_TYPE				0
#define ALL_OBJECTS					1
#define BULLETWORLD_OBJECT			2
#define CAMERA_OBJECT				3
#define LIGHT_OBJECT				4
#define TIMER_OBJECT				5
#define CAMERATHIRDPERSON_OBJECT	6
#define CAMERAFREE_OBJECT			7
#define CSPHERE_OBJECT				8
#define CBOX_OBJECT					9
#define CCYLINDER_OBJECT			10
#define CCAPSULE_OBJECT				11
#define CCONE_OBJECT				12
#define CSTATICPLANE_OBJECT			13
#define CRIGIDBODY_OBJECT			14
//insertNewObjectTypeHere

#endif
