// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
#include "Engine/IO/Mouse.h"
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!"); // C++11 string literals are constant data
    
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite testsprite = Sprite("Assets/Art/BiPlane.png",-100,-100);
    testsprite.SetScale(0.25f);

    while (true) {
        engine.Update();
        testsprite.Update();

        testsprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());
        
        engine.BeginRender();
        testsprite.Render();
        engine.EndRender();
    }

    return 0;
}

