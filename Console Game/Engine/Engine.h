// #pragma - once ensures header files are  not included  multiple times
//         - windows
// platform equilvalent version 


// Class handles window and rendering of the frames

#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")  // link library


#include <iostream>
using namespace std;


class Engine
{

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float GetDT();

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle); // const added

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	static float dt; // static so don't have to insentiate a new engine to check delta time
	float lastTime;
};


#endif