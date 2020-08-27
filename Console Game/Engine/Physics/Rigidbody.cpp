#include "Rigidbody.h"
#include "../Engine.h"


#include <vector>

using namespace std;

Rigidbody::Rigidbody()
{
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size)
{
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	size = _size;
	scale = _scale;
	
}

void Rigidbody::Update()
{
	
	vel.x *= friction;
	vel.y *= friction;
	*pos = *pos + (vel * Engine::GetDT());
	
	vel = Vector3(0); 


	// Clamp User to game boundaries

	// Top
	if (pos->y > Engine::SCREEN_HEIGHT - size->y * scale->y / 2)
	{
		pos->y = Engine::SCREEN_HEIGHT - size->y * scale->y / 2;
	}

	// Bottom
	if (pos->y < size->y * scale->y / 2)
	{
		pos->y = size->y * scale->y / 2;
	}
	
	// Right
	if (pos->x > Engine::SCREEN_WIDTH - size->x * scale->x / 2)
	{
		pos->x = size->x * scale->x / 2;
	}

	// Left 
	if  (pos->x < size->x * scale->x / 2)
	{
		pos->x = size->x * scale->x / 2;
	}

}


void Rigidbody::Render(Vector3 c)  // colour vector
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z); // (*pos).x 
	glRotatef(*rot, 0,0,1);
	glScalef(scale->x, scale->y, scale->z);

}

void Rigidbody::SetVel(Vector3 _vel)
{
	vel = _vel;
}

void Rigidbody::AddForce(Vector3 force)
{
	vel = vel + force;

}

Vector3 Rigidbody::GetVel()
{
	return vel;
}



