/*
    GameObject.cpp
    Purpose: Object maker

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(char* texturesheet, int x, int y, float scale, int* color, const int type)
{
	
	objType = type;
	objScale = scale;
	objParameter = texturesheet;
	
	if(type == 1)
	{
		objTexture = TextureManager::LoadTexture(texturesheet);
	}
	else if(type == 2)
	{	
		objTexture = TextureManager::newText(texturesheet, color[0], color[1], color[2], scale);
	}
	
	objColor = color;
	
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
	
	if(objType == 1)
	{
		destRect.w = w * objScale;
		destRect.h = h * objScale;
	}
	else if(objType == 2)
	{
		destRect.w = w;
		destRect.h = h;
	}
}

void GameObject::scaleTo(float scaleFactor)
{
	if(objType == 1){
		objScale = scaleFactor;
	}
	else if(objType == 2)
	{
		objScale = scaleFactor;
		objTexture = TextureManager::newText(objParameter, objColor[0], objColor[1], objColor[2], objScale);
	}
}

void GameObject::scaleBy(float scaleFactor)
{
	if(objType == 1){
		objScale = objScale * scaleFactor;
	}
	else if(objType == 2)
	{
		objScale = objScale * scaleFactor;
		objTexture = TextureManager::newText(objParameter, objColor[0], objColor[1], objColor[2], objScale);
	}
}

void GameObject::changeText(char* newString)
{
	if(objType == 2){
		objTexture = TextureManager::newText(newString, objColor[0], objColor[1], objColor[2], objScale);
		objParameter = newString;
	}
}