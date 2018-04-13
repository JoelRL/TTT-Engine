/*
    GameObject.cpp
    Purpose: Object maker

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, float scale, int* color, const int type)
{
	
	objScale = scale;
	
	if(type == 1)
	{
		objTexture = TextureManager::LoadTexture(texturesheet);
	}
	else if(type == 2)
	{	
		objTexture = TextureManager::newText(texturesheet, color[0], color[1], color[2], scale);
		objScale = 1;
	}
	
	xpos = x;
	ypos = y;
}

void GameObject::move(int x, int y)
{
	xpos = xpos + x;
	ypos = ypos + y;
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
	destRect.w = w * objScale;
	destRect.h = h * objScale;
}