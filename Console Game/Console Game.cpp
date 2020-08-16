// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!"); // C++11 string literals are constant data
    
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite testsprite = Sprite("Assets/Art/BiPlane.png",0,0);
    testsprite.SetScale(0.25f);

    while (true) {
        engine.Update(); // point where game frame starts
        testsprite.Update();

        //testsprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());
        
        if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))  // left mouse button just pressed
        {
            testsprite.RotateBy(100);
        }


        if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))  
        {
            testsprite.RotateBy(-100);
        }


        if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
        {
            testsprite.RotateBy(100);
        }

        if (Keyboard::Key(GLFW_KEY_W))
        {
            testsprite.MoveUp();
        }

        if (Keyboard::Key(GLFW_KEY_S))
        {
            testsprite.MoveDown();
        }

        if (Keyboard::Key(GLFW_KEY_A))
        {
            testsprite.MoveLeft();
        }

        if (Keyboard::Key(GLFW_KEY_D))
        {
            testsprite.MoveRight();
        }

        engine.BeginRender();
        testsprite.Render();
        engine.EndRender();
    }

    return 0;
}

