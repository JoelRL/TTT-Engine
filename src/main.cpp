/*
    main.cpp
    Purpose: Main file

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "WindowManager.h"

int main(int argc, char *argv[])
{
	
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	newGameWindow("Game.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	Uint32 frameStart;
	
	int frameTime;
	
	while (game->running())
	{
		
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		
		game->update();
		
		game->render();
		
		frameTime = SDL_GetTicks() - frameStart;
		
		if( frameDelay > frameTime )
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}
	
	game->clean();
	
	return 0;
}