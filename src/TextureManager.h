/*
    TextureManager.h
    Purpose: TextureManager header file

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "game.h"

class TextureManager
{
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
			//LoadTexture - Load and return an SDL texture
			//@param fileName - String of path to texture
		
		static SDL_Texture* newText(const char* string, int r, int g, int b, int size);
			//newText - Create and return SDL text texture
			//@param string - String to display in text
			//@param r - Color red
			//@param g - Color green
			//@param b - Color blue
};

#endif // TextureManager.h //