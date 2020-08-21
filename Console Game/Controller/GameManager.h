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
	enum class State
	{
		START,
		GAMEPLAY,
		GAMEOVER,
		COUNT
	};

	GameManager();
	~GameManager();

	void Start();
	


private:
	void SetState(State state);

	Engine engine;
	Flapper * flapper;

	State state;

	Sprite StartSprite;     // can be accessed by class functions
	Sprite GameoverSprite;
};


#endif