// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
#include <string>
#include "Flapper/Flapper.h"
#include "Flapper/GameManager.h"
using namespace std;


int main()
{
    cout << "Hello World!\n";

    Engine engine;

    engine.Initialize("WindowTitle!"); // C++11 string literals are constant data
    
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite testsprite = Sprite("Assets/Art/BiPlane.png", Vector3(100, 100, 0));
    testsprite.SetScale(0.20f);

    Flapper player(testsprite);
    GameManager gm(&player);


    while (true) {   // WHILE LOOP CAUSES TEXTURE TO FALL DOWN
        engine.Update(); 
        player.Update();  
        gm.Update();
      
       
        engine.BeginRender();
        player.Render();
        engine.EndRender();
    }

    return 0;
}

