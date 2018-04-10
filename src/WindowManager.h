#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "game.h"

Game *game;
Game *game2;

bool secondScreen = false;

void newGameWindow(const char* title, int x, int y, int w, int h, bool full, int id)
{
	if(id == 1)
	{
		game = new Game();
	
		game->init(title, x, y, w, h, full, id);
	}
	else if(id == 2)
	{
		game2 = new Game();
	
		game2->init(title, x, y, w, h, full, id);
		
		secondScreen = true;
	}
}

#endif // WindowManager.h //