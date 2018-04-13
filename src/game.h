/*
    Game.h
    Purpose:game class file

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <vector>

#include "GameObject.h"

class Game
{
	public:
		
		Game();
			// Main constructor
		
		~Game();
			// Main deconstructor
		
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, unsigned int ID);
			//init - Initialize SDL, create a window, create a renderer, and initialize objects
			//@param title - Window title
			//@param xpos - X position of window
			//@param ypos - Y position of window
			//@param width - width of window
			//@param height - height of window
			//@param fullscreen - If full screen true or false
			//@param ID - The ID for the window (e.g. ID #1 is main window, #2 is secondary)
		
		void handleEvents();
			//handleEvents - Handles all events (e.g. Keyboard and mouse)
		
		void update();
			//update - Updates all worldObjects (The vector with all game objects)
		
		void render();
			//render - Draws all worldObjects (The vector with all game objects)
		
		void clean();
			//clean - Destroys window and renderer. Then properly quits SDL
		
		bool running() { return isRunning; }
			//running - Check if game running
			//@return - If "isRunning" is true or false
		
		static SDL_Renderer *renderer; // Main renderer
		
		void newObject(int x, int y, const char* texture, float scale);
			//newObject - Create a new object in the game
			//@param x - X value of object
			//@param y - Y value of object
			//@param texture - Path to texture file
			
		void newTextObject(int x, int y, const char* text, float size);
			//newTextObject - Create a new text object
			//@param x - X value of text object
			//@param y - Y value of text object
			//@param text - String to print
			
		SDL_Texture* newText(int x, int y, const char* string);
			
		SDL_Event gameEvent;
		
		bool isRunning; //Bool value that keeps track if game running
		
		int* getTextColor() { return textColor; }
		
		void changeTextColor(int r, int g, int b);
		
	private:
	
		SDL_Window *window; //Main SDL Window
		
		SDL_Texture* text1; // Text
		
		int windowID;
		
		int textColor[3] = { 255, 255, 255 };
};

#endif // GAME_H //