// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef _STDAFX_H_
#define _STDAFX_H_

//#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#include "glut.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

#include "GameIncludes.h"

#include "DebugOutput.h"

// object types

#define NO_OBJECT_TYPE 0
#define ALL_OBJECTS 1
#define BULLETWORLD_OBJECT 2
#define BULLETCOLLISIONSHAPE_OBJECT 3
#define BULLETRIGIDBODY_OBJECT 4
#define CAMERA_OBJECT 5
#define LIGHT_OBJECT 6
#define TIMER_OBJECT 7


#define	SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

static char*	WINDOW_NAME = "Game";

/** Lights settings **/
const GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
const GLfloat light_diffuse[]= { 0.5f, 0.5f, 0.5f, 0.5f };
const GLfloat light_specular[]= { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat light_position[]= { 10.0, 10.0f, 10.0, 1.0f };

/** Materials settings **/ 
const GLfloat p1ambient[]= { 1.0f, 0.0f, 0.0f, 0.0f };
const GLfloat mat_diffuse[]= { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat mat_specular[]= { 0.7f, 0.7f, 0.7f, 0.0f };
const GLfloat mat_shininess[]= { 1.0f };

#endif