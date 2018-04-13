/*
    TextureManager.cpp
    Purpose: Create and manage textures

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName); //Temporary surface to make texture from
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface); //Create texture on temporary surface
	SDL_FreeSurface(tempSurface); //Delete the surface
	
	return tex; //Return texture
}

SDL_Texture* TextureManager::newText(const char* string, int r, int g, int b, int size)
{
	
	TTF_Font *font = TTF_OpenFont("assets/arial.ttf", size); //Create new font with param size
	SDL_Color color = { r, g, b }; //Set up color of text
	SDL_Surface* tempSurface = TTF_RenderText_Solid(font,string, color); //Temporary surface to make text from
	SDL_Texture* textT = SDL_CreateTextureFromSurface(Game::renderer, tempSurface); //Create texture on temporary surface
	TTF_CloseFont(font); //Delete font
	SDL_FreeSurface(tempSurface); //Delete the surface
	
	return textT; //Return texture
}