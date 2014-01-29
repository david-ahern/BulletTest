// BulletTest2.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"

class Game;

GameEngine* GameEngineInstance = GameEngine::GetInstance();

int main(int argc, char **argv)
{
#if defined(DEBUG_OUTPUT)
	openDebugOutputFile();
#endif

	GameEngineInstance->Init(argc, argv);

	Game* game = new Game("game");
	game->Init();
	GameEngineInstance->AddScreen(game);
	GameEngineInstance->SwitchTo("game");

	disableDebugOutput();

	GameEngineInstance->MainLoop();

#if defined(DEBUG_OUTPUT)
	closeDebugOutputFile();
#endif
}