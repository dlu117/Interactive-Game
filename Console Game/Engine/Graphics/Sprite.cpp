#include "Sprite.h"


Sprite::Sprite()
{
	xpos = 0;
	ypos = 0;
	rot = 0;
	texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	xpos = 0;
	ypos = 0;
	rot = 0;
}

Sprite::Sprite(string imagePath, float _xpos, float y_pos)
{
	texture = Texture(imagePath);
	xpos = _xpos;
	ypos = y_pos;
	rot = 0; 
}

void Sprite::Update()
{
	rot++;
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

void Sprite::SetPos(float x, float y)
{
	xpos = x;
	ypos = y;

}

void Sprite::SetRot(float x)
{
	rot = x;
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