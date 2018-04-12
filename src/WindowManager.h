#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "game.h"

Game *game;

void newGameWindow(const char* title, int x, int y, int w, int h, bool full, int id)
{
	game = new Game();
	
	game->init(title, x, y, w, h, full, id);
}

#endif // WindowManager.h //