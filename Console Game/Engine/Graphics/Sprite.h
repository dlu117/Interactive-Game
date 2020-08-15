#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"


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


private:
	Texture texture;
	float xpos;
	float ypos;
};

#endif