#include "../Engine/Engine.h";
#include "../Engine/Graphics/Sprite.h"

#ifndef CRATE
#define CRATE

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Crate
{
public:
	static Sprite* crateSprite;
	
	Crate();
	Crate(int n);
	~Crate();



private:
	Sprite startSprite;
	Sprite endSprite;


};

#endif
