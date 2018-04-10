/*
    GameObject.h
    Purpose: GameObject header file

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"

class GameObject
{
	public:
	
		GameObject(const char* texturesheet, int x, int y);
			//GameObject - main construct
			//@param texturesheet - Path to texture file
			//@param x - X value of object
			//@param y - Y value of object
		
		~GameObject();
			//~GameObject - main deconstructor
		
		void Update();
			//Update - Update function for objects
		
		int getX() { return xpos; }
			//GetX - Gets and returns X value of object
			//@return - X value
			
		int getY() { return ypos; }
			//GetY - Gets and returns Y value of object
			//@return - Y value
		
		SDL_Texture* objTexture; // Objects SDL Texture
		
		SDL_Rect srcRect, destRect; // Objects source and destination SDL rectangles
		
	private:
		int xpos; // Object X position
		int ypos; // Object Y position
};

#endif // GameObject.h //