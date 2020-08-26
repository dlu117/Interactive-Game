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
	
	void CreateLevel();


private:
	void SetState(State state);

	Engine engine;
	Flapper * flapper;

	State state;

	Sprite StartSprite;     // can be accessed by class functions
	Sprite GameoverSprite;

	wstring slevel; 

	int LevelWidth;
	int LevelHeight;

	int TileWidth;
	int TileHeight;

	float CameraPosX = 0.0f;
	float CameraPosY = 0.0f;

};


#endif