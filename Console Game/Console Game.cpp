// Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Graphics/Sprite.h"
#include "Engine/Engine.h"
#include <iostream>
#include <string>
#include "Controller/Flapper.h"
#include "Controller/GameManager.h"
using namespace std;


int main()
{
    cout << "Welcome!\n";

    GameManager gameManager;
    gameManager.Start();
   

    return 0;
}

