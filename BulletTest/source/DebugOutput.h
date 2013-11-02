#pragma once
#ifndef _DEBUGOUTPUT_H_
#define _DEBUGOUTPUT_H_

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>

class Timer;

using namespace std;

#define BEGIN 0
#define END 1

typedef struct Function
{
	char* className;
	char* objectName;
	char* functionName;
	double startTime;
	int objectType;
}function;


extern bool openDebugOutputFile();
extern void closeDebugOutputFile();
extern void enableDebugOutput();
extern void disableDebugOutput();
extern void debugPrint(char*);
extern void debugPrint(char*, char*);
extern void debugPrint(char*, char*, char*);
extern void debugPrint(char*, char*, int);
extern void debugPrint(char*, char*, char*, int);
extern void debugPrint(char*, char*, int, int);
extern void debugPrint(char*, char*, char*, int, int);


#endif