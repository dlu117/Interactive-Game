// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
#include <string>
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Flapper/Flapper.h"
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!"); // C++11 string literals are constant data
    
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite testsprite = Sprite("Assets/Art/BiPlane.png", Vector3(100, 100, 0));
    testsprite.SetScale(0.25f);

    Flapper player(testsprite);



    while (true) {
        engine.Update(); // point where game frame starts
        player.Update();

        //testsprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());
        
        if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))  // left mouse button just pressed
        {
            player.GetSprite().RotateBy(100);
        }


        if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))  
        {
            player.GetSprite().RotateBy(-100);
        }


        if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
        {
            player.GetSprite().RotateBy(100);
        }

        if (Keyboard::Key(GLFW_KEY_W))
        {
            player.GetRB().AddForce(Vector3(0, 200, 0));
        }

        if (Keyboard::Key(GLFW_KEY_S))
        {
            player.GetRB().AddForce(Vector3(0, -200, 0));
        }

        if (Keyboard::Key(GLFW_KEY_A))
        {
            player.GetRB().AddForce(Vector3(-200, 0,0));
        }

        if (Keyboard::Key(GLFW_KEY_D))
        {
            player.GetRB().AddForce(Vector3(200, 0, 0));
        }

        engine.BeginRender();
        player.Render();
        engine.EndRender();
    }

    return 0;
}

