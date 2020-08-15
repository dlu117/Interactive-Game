// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!"); // C++11 string literals are constant data
    
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite testsprite = Sprite("Assets/Art/cloud2.png",100,100);

    while (true) {
        engine.Update();
        testsprite.Update();
        engine.BeginRender();
        testsprite.Render();
        engine.EndRender();
    }

    return 0;
}

