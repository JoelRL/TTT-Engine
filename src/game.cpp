/*
    game.cpp
    Purpose: Game file

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"

std::vector<GameObject*> worldObjects;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
	
}

Game::~Game()
{
	
}

/* void changeTextColor(int r, int g, int b)
{
	textColor[0] = r;
	textColor[1] = g;
	textColor[2] = b;
} */

void Game::newObject(int x, int y, const char* texture, float scale)
{
	
	GameObject* object;
	
	object = new GameObject(texture, x, y, scale, 1);
	
	worldObjects.push_back(object);
}

void Game::newTextObject(int x, int y, const char* text, float size)
{
	GameObject* object;
	
	int *color = getTextColor();
	
	std::cout << "current color: " << color[0] << "," << color[1] << "," << color[2] << std::endl;
	
	object = new GameObject(text, x, y, size, 2);
	
	worldObjects.push_back(object);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, unsigned int ID)
{
	
	TTF_Init();
	
	windowID = ID;
	
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;	
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initilized sucessfully" << std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		if (window)
		{
			std::cout << "Window created sucessfully" <<std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		if (renderer)
		{
			if(windowID == 1)
			{
				SDL_SetRenderDrawColor(renderer,  255, 100, 100, 255);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer,  100, 100, 255, 255);
			}
			
			std::cout << "Renderer created sucessfully" << std::endl;
		}
		
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	if(windowID == 1)
	{
		// INITIALIZE worldObjects
		
		newObject(100,100,"assets/test.png", 0.5);
		
		newObject(300,250,"assets/test2.png", 0.5);
		
		newObject(400,280,"assets/test2.png", 0.5);
		
		newTextObject(0,0,"Press the arrow keys to move!", 20);
		
		changeColor(120,255,120);
		
		newTextObject(0,25,"WOW!!", 20);
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	gameEvent = event;

	SDL_Window* targetWindow = SDL_GetWindowFromID(event.window.windowID);
	const char* title = SDL_GetWindowTitle(targetWindow);
	
	switch (event.type)
	{
		case SDL_WINDOWEVENT:
			switch( event.window.event )
			{
				
			}
			break;
		// Keyboard handling
		case SDL_KEYDOWN:
			switch( event.key.keysym.sym )
			{
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				case SDLK_RIGHT:
					worldObjects[0]->move(3,0);
					break;
				case SDLK_LEFT:
					worldObjects[0]->move(-3,0);
					break;
				case SDLK_UP:
					worldObjects[0]->move(0,-3);
					break;
				case SDLK_DOWN:
					worldObjects[0]->move(0,3);
					break;
				default:
					break;
			}
			break;
		// Exit button handling
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	// UPDATE ALL worldObjects
	for(unsigned int i = 0; i < worldObjects.size(); i++)
	{
		worldObjects[i]->Update();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	// DRAW ALL worldObjects
	for(unsigned int i = 0; i < worldObjects.size(); i++)
	{
		SDL_RenderCopy(Game::renderer, worldObjects[i]->objTexture, &worldObjects[i]->srcRect, &worldObjects[i]->destRect);
	}
	
	SDL_RenderCopy(Game::renderer, text1, NULL, NULL);
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Finished cleaning up" << std::endl;
}