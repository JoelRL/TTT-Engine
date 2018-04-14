#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "game.h"

Game *game;

Game *game2;

void newGameWindow(const char* title, int x, int y, int w, int h, bool full)
{
	game = new Game();
	
	game->init(title, x, y, w, h, full);
}

#endif // WindowManager.h //