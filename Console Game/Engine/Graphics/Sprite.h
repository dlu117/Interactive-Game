#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

// displays texture at a certain location

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xpos, float y_pos);

	void Update();
	void Render();

	
	void SetPos(float x, float y);
	void SetRot(float x);
	void SetScale(float x);
	void SetScale(float x, float y);
	

private:
	Texture texture;
	float xpos;
	float ypos;
	float rot; //rotation
	float xScale;
	float yScale;
};

#endif