#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "game.h"

class TextureManager
{
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
};

#endif /* TextureManager.h */