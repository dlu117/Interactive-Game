#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite()
{
	//xpos = 0;
	//ypos = 0;
	pos = Vector3(0);
	rot = 0;
	speed = 500;
	texture = Texture();
	scale = Vector3(1);
	size = Vector3(0);
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	//xpos = 0;
	//ypos = 0;
	pos = Vector3(0);
	rot = 0; 
	speed = 500;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);

}

Sprite::Sprite(string imagePath, Vector3 v) //float _xpos, float y_pos
{
	texture = Texture(imagePath);
	//xpos = _xpos;
	//ypos = y_pos;
	pos = v;
	rot = 0;
	speed = 500;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE 

	//glTranslatef(xpos, ypos, 0);
	//glRotatef(rot, 0, 0, 1);
	//glScalef(xScale,yScale,1);

	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);


	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);   // taking each corner of texture image and place it on console screen
	{
		glTexCoord2f(0, 0);		glVertex2i(0,0);
		glTexCoord2f(1, 0);		glVertex2i(texture.GetWidth(), 0);
		glTexCoord2f(1, 1);		glVertex2i(texture.GetWidth(), texture.GetHeight());
		glTexCoord2f(0, 1);		glVertex2i(0, texture.GetHeight());
	}
	glEnd(); 

	glDisable(GL_TEXTURE_2D);
}   

void Sprite::SpeedTo(float x)
{
	speed = x;

}

void Sprite::SpeedBy(float x)
{
	speed += x;

}


void Sprite::MoveTo(Vector3 v)
{
	//xpos = x;
	//ypos = y;
	pos = v;

}

void Sprite::MoveBy(Vector3 v) //float x, float y
{
	pos = pos + (v * Engine::GetDT());
	//xpos += (x * Engine::GetDT());
	//ypos += (y * Engine::GetDT());

}


void Sprite::RotateTo(float x)
{
	rot = x;
}

void Sprite::RotateBy(float x)
{
	rot += (speed * Engine::GetDT());
}

void Sprite::SetScale(float x)
{
	//xScale = x;
	//yScale = x;
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v) //float x, float y
{
	//xScale = x;
	//yScale = y;
	scale = v;
}

void Sprite::MoveLeft()
{
	//xpos -= (speed *  Engine::GetDT());
	pos = pos - Vector3((speed * Engine::GetDT()), 0, 0);
}


void Sprite::MoveRight()
{
	//xpos += (speed * Engine::GetDT());
	pos = pos + Vector3((speed * Engine::GetDT()), 0, 0);
}


void Sprite::MoveUp()
{
	//ypos += (speed * Engine::GetDT());
	pos = pos + Vector3(0, (speed * Engine::GetDT()), 0);
}


void Sprite::MoveDown()
{
	//ypos -= (speed * Engine::GetDT());
	pos = pos - Vector3(0, (speed * Engine::GetDT()), 0);
}

Vector3* Sprite::GetPos()
{
	return &pos;
}

float* Sprite::GetRot()
{
	return &rot;
}

Vector3* Sprite::GetScale()
{
	return &scale;
}

Vector3* Sprite::GetSize()
{
	return &size;
}