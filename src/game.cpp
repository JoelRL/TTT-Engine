#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
	
}

Game::~Game()
{
	
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
	
	player = new GameObject("assets/test.png", 0, 0);
	
	enemy = new GameObject("assets/test2.png", 0, 200);
	
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
	player->Update();
	enemy->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	// Draw shit
	player->Render();
	enemy->Render();
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Finished cleaning up" << std::endl;
}