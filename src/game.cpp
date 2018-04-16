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

SDL_Event Game::event;

Game::Game()
{
	
}

Game::~Game()
{
	
}

void Game::changeColor(int r, int g, int b)
{
	gameColor[0] = r;
	gameColor[1] = g;
	gameColor[2] = b;
}

void Game::newObject(int x, int y, char* texture, float scale)
{
	
	int *color = getColor();
	
	GameObject* object;
	
	object = new GameObject(texture, x, y, scale, color, 1, 0, 0);
	
	worldObjects.push_back(object);
}

void Game::newTextObject(int x, int y, char* text, float size)
{
	GameObject* object;
	
	int *color = getColor();
	
	object = new GameObject(text, x, y, size, color, 2, 0, 0);
	
	worldObjects.push_back(object);
}

void Game::newRectangleObject(int x, int y, int w, int h, char* type)
{
	GameObject* object;
	
	int *color = getColor();
	
	object = new GameObject(type, x, y, 0, color, 3, w, h);
	
	worldObjects.push_back(object);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	
	TTF_Init();
	
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
			SDL_SetRenderDrawColor(renderer,  backgroundColor[0], backgroundColor[1], backgroundColor[2], 255);
			
			std::cout << "Renderer created sucessfully" << std::endl;
		}
		
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	// INITIALIZE worldObjects //
	
	newObject(100,100,"assets/test.png", 0.5);
	
	newObject(300,250,"assets/test2.png", 0.5);
	
	newObject(400,280,"assets/test2.png", 0.5);
	
	changeColor(255,0,0);
	
	newTextObject(0,0,"Press the arrow keys to move!", 30);
	
	changeColor(50,50,255);
	
	newRectangleObject(100,200,50,50,"fill");
	
	changeColor(255,255,0);
	
	newTextObject(0,35,"WOW!!", 30);
}

void Game::handleEvents()
{
	
	SDL_PollEvent(&event);

	SDL_Window* targetWindow = SDL_GetWindowFromID(event.window.windowID);
	const char* title = SDL_GetWindowTitle(targetWindow);
	
	switch (event.type)
	{
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
				case SDLK_s:
					worldObjects[0]->scaleBy(0.5);
					break;
				case SDLK_a:
					worldObjects[0]->scaleTo(1);
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
	
	// Draw ALL worldObjects
	for(unsigned int i = 0; i < worldObjects.size(); i++)
	{
		if(worldObjects[i]->getType() == 1 || worldObjects[i]->getType() == 2)
		{
			SDL_RenderCopy(Game::renderer, worldObjects[i]->objTexture, &worldObjects[i]->srcRect, &worldObjects[i]->destRect);
		}
		else if(worldObjects[i]->getType() == 3)
		{
			
			SDL_SetRenderDrawColor(Game::renderer, worldObjects[i]->getObjColor(1), worldObjects[i]->getObjColor(2), worldObjects[i]->getObjColor(3), 255);
			
			SDL_RenderDrawRect(Game::renderer, &worldObjects[i]->destRect);
			
			if(worldObjects[i]->getObjParameter() == "fill")
			{
				SDL_RenderFillRect(Game::renderer, &worldObjects[i]->destRect);
			}
		}
	}
	
	SDL_SetRenderDrawColor(Game::renderer,  backgroundColor[0], backgroundColor[1], backgroundColor[2], 255);
	
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