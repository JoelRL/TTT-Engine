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
	
		GameObject(char* texturesheet, int x, int y, float scale, int* color, const int type);
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
			
		void move(int x, int y);
			//move - Moves object corresponding to X and Y parameters
			//@param x - X value to move
			//@param y - Y value to move
			
		void scaleTo(float scaleFactor);
			//scaleTo - Scale texture to scale factor
			//@param scaleFactor - Number to scale to
		
		void scaleBy(float scaleFactor);
			//scaleTo - Scale texture by scale factor
			//@param scaleFactor - Number to scale by
			
		void changeText(char* newString);
			//changeText - Change the text in an object
			//@param newString - New string for text
		
		SDL_Texture* objTexture; // Objects SDL Texture
		
		SDL_Rect srcRect, destRect; // Objects source and destination SDL rectangles
		
	private:
		int objType; // Object type (e.g. Sprite, Text)
		char* objParameter; // Objects texturesheet or text string depending on type
		int xpos; // Object X position
		int ypos; // Object Y position
		float objScale; // Object sprite scale number or text size depending on type
		int *objColor; // Color of object
};

#endif // GameObject.h //