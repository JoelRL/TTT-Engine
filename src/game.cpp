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

void Game::newObject(int x, int y, const char* texture)
{
	GameObject* object;
	
	object = new GameObject(texture, x, y);
	
	worldObjects.push_back(object);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	
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
			SDL_SetRenderDrawColor(renderer,  255, 100, 100, 255);
			std::cout << "Renderer created sucessfully" << std::endl;
		}
		
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	// INITIALIZE worldObjects
	
	newObject(100,100,"assets/test.png");
	
	newObject(300,250,"assets/test2.png");
	
	newObject(400,280,"assets/test2.png");
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		// Keyboard handling
		case SDL_KEYDOWN:
			switch( event.key.keysym.sym ){
                case SDLK_ESCAPE:
					isRunning = false;
					break;
				default:
					break;
			}
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
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Finished cleaning up" << std::endl;
}