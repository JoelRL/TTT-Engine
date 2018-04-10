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
		static SDL_Texture* LoadTexture(const char* fileName); // SDL Texture
};

#endif // TextureManager.h //