#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "../Engine/Engine.h"
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"
#include "Flapper.h"


class GameManager
{

public:
	GameManager(Flapper* _flapper);
	void Update();


private:
	Flapper* flapper;


};


#endif