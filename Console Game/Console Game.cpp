// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Engine.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!");

    while (true) {
        engine.Update();
        engine.Render();
    }

    return 0;
}

