#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite()
{
	xpos = 0;
	ypos = 0;
	rot = 0;
	speed = 500;
	texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	xpos = 0;
	ypos = 0;
	rot = 0; 
	speed = 500;
}

Sprite::Sprite(string imagePath, float _xpos, float y_pos)
{
	texture = Texture(imagePath);
	xpos = _xpos;
	ypos = y_pos;
	rot = 0;
	speed = 500;
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
	glTranslatef(xpos, ypos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale,yScale,1);


	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);   // taking each corner of texture image and place it on console screen
	{
		glTexCoord2f(0, 0);		glVertex2f(0,0);
		glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth(), 0);
		glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth(), ypos + texture.GetHeight());
		glTexCoord2f(0, 1);		glVertex2f(0,texture.GetHeight());
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


void Sprite::MoveTo(float x, float y)
{
	xpos = x;
	ypos = y;

}

void Sprite::MoveBy(float x, float y)
{
	xpos += (x * Engine::GetDT());
	ypos += (y * Engine::GetDT());

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
	xScale = x;
	yScale = x;
}

void Sprite::SetScale(float x, float y)
{
	xScale = x;
	yScale = y;
}

void Sprite::MoveLeft()
{
	xpos -= (speed *  Engine::GetDT());
}


void Sprite::MoveRight()
{
	xpos += (speed * Engine::GetDT());
}


void Sprite::MoveUp()
{
	ypos += (speed * Engine::GetDT());
}


void Sprite::MoveDown()
{
	ypos -= (speed * Engine::GetDT());
}