/*
    TextureManager.cpp
    Purpose: Create and manage textures

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName); //Temporal surface to make texture from
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface); //Create texture on temporal surface
	SDL_FreeSurface(tempSurface); //Delete the surface
	
	return tex; //Return texture
}