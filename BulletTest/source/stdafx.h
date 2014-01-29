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
#include <map>

#include "glut.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

#include "GameIncludes.h"

#include "DebugOutput.h"

// define this to allow for the debug output to run, comment out to disable output
#define DEBUG_OUTPUT


#define	SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

static char*	WINDOW_NAME = "Game";

/** Lights settings **/
const GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
const GLfloat light_diffuse[]= { 0.5f, 0.5f, 0.5f, 0.5f };
const GLfloat light_specular[]= { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat light_position[]= { 10.0, 10.0f, 10.0, 1.0f };

/** Materials settings **/ 
const GLfloat p1ambient[]= { 1.0f, 0.0f, 0.0f, 0.0f };
const GLfloat mat_diffuse[]= { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat mat_specular[]= { 0.3f, 0.3f, 0.3f, 0.0f };
const GLfloat mat_shininess[]= { 1.0f };

const float PI = 3.141592654;
const float DEG_TO_RAD = PI/180;
const float RAD_TO_DEG = 180/PI;

#endif