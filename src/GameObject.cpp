/*
    GameObject.cpp
    Purpose: Object maker

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	
	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	
	// Get texture width and height
	int w, h;
	SDL_QueryTexture(objTexture, NULL, NULL, &w, &h);
	
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = w;
	srcRect.h = h;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 458/2;
	destRect.h = 436/2;
}