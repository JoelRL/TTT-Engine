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
	
		GameObject(char* texturesheet, int x, int y, float scale, int* color, const int type, int w, int h);
			//GameObject - main construct
			//@param texturesheet - Path to texture file
			//@param x - X value of object
			//@param y - Y value of object
		
		~GameObject();
			//~GameObject - main deconstructor
		
		void Update();
			//Update - Update function for objects
		
		int getType() { return objType; }
			//getType - Get object type
			//@return - Number ID of type of object
		
		int getX() { return xpos; }
			//getX - Gets and returns X value of object
			//@return - X value
			
		int getY() { return ypos; }
			//getY - Gets and returns Y value of object
			//@return - Y value
			
		char* getObjParameter() { return objParameter; }
			//getObjParameter - Gets and returns the parameter for an object (e.g. Texturesheet path, string contents, rectangle draw type)
			//@return - The object parameter
			
		int getObjColor(int color);
			//getObjColor - Gets and returns color
			//@return - The array of the objects color
			
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
		int objColorR; // Color of object
		int objColorG; // Color of object
		int objColorB; // Color of object
		int objW;
		int objH;
};

#endif // GameObject.h //