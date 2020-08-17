#include "Flapper.h"

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

Flapper::Flapper()
{
	
}

Flapper::Flapper(Sprite _sprite)
{
	sprite = _sprite;
	rb.Initialize(0.8f, -10, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}


void Flapper::Update()
{

	sprite.Update();
	rb.Update();

}

void Flapper::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}


Sprite& Flapper::GetSprite() //reference so can modify them
{
	return sprite;
}

Rigidbody& Flapper::GetRB()
{
	return rb;
}
