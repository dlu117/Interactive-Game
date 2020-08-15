// #pragma - once ensures header files are  not included  multiple times
//         - windows


// platform equilvalent version 

#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")  // link library


#include <iostream>
using namespace std;


class Engine
{

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle); 

	void Update();
	void Render();

private:
	static GLFWwindow* window;

};


#endif