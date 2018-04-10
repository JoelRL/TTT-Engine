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
	
	newGameWindow("Game.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, 1);
	
	Uint32 frameStart;
	
	int frameTime;
	
	while (game->running())
	{
		
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		
		switch(game->gameEvent.type)
		{
			case SDL_KEYDOWN:
				switch(game->gameEvent.key.keysym.sym)
				{
					case SDLK_a:
						if(secondScreen == false)
						{
							newGameWindow("Other screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 220, false, 2);
						}
						break;
					case SDLK_ESCAPE:
						game->isRunning = false;
						break;
					default:
						break;
				}
			default:
				break;
		}
		
		game->update();
		
		game->render();
		
		if(secondScreen)
		{
			
			game2->handleEvents();
			
			switch(game2->gameEvent.type)
			{
				case SDL_KEYDOWN:
					switch(game2->gameEvent.key.keysym.sym)
					{
						case SDLK_s:
							std::cout << "snake" << std::endl;
							break;
						case SDLK_ESCAPE:
							SDL_DestroyWindow(game2->window);
							SDL_DestroyRenderer(game2->renderer);
							break;
						default:
							break;
					}
				default:
					break;
			}
			
			game2->update();
			
			game2->render();
		}
		
		frameTime = SDL_GetTicks() - frameStart;
		
		if( frameDelay > frameTime )
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}
	
	game->clean();
	
	if(secondScreen)
	{
		game2->clean();
	}
	
	return 0;
}