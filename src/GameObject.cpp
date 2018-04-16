/*
    GameObject.cpp
    Purpose: Object maker

    @author Joel Rodiel-Lucero
    @version 1.0 4/3/18
*/

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(char* texturesheet, int x, int y, float scale, int* color, const int type, int w, int h)
{
	
	objType = type;
	
	if(type == 1 || type == 2)
	{
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
		
		objColorR = color[0];
		objColorG = color[1];
		objColorB = color[2];
		
		xpos = x;
		ypos = y;
	}
	else if(type == 3)
	{
	
		objParameter = texturesheet;
		
		objColorR = color[0];
		objColorG = color[1];
		objColorB = color[2];
		
		xpos = x;
		ypos = y;
		objW = w;
		objH = h;
	}
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
	
	if(objType == 1 || objType == 2)
	{
		SDL_QueryTexture(objTexture, NULL, NULL, &w, &h);
	}
	else if(objType == 3)
	{
		w = objW;
		h = objH;
	}
	
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
	else if(objType == 2 || objType == 3)
	{
		destRect.w = w;
		destRect.h = h;
	}
}

int GameObject::getObjColor(int color)
{
	if(color == 1)
	{
		return objColorR;
	}
	else if(color == 2)
	{
		return objColorG;
	}
	else if(color == 3)
	{
		return objColorB;
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
		objTexture = TextureManager::newText(objParameter, objColorR, objColorG, objColorB, objScale);
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
		objTexture = TextureManager::newText(objParameter, objColorR, objColorG, objColorB, objScale);
	}
}

void GameObject::changeText(char* newString)
{
	if(objType == 2){
		objTexture = TextureManager::newText(newString, objColorR, objColorG, objColorB, objScale);
		objParameter = newString;
	}
}