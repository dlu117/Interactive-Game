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
	vel.y += gravity;
	cout << "x: " << vel.x << "y: " << vel.y << endl;
	*pos = *pos + (vel * Engine::GetDT());
	vel = Vector3(0); 

}

void Rigidbody::Render(Vector3 c)  // colour vector
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z); // or could do (*pos).x 
	glRotatef(*rot, 0,0,1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{

		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);

		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);
	}
	
	glEnd();

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



/*
bool Rigidbody::IsColliding(const Rigidbody& rbA, const Rigidbody& rbB)
{
	Rect rcA = rbA.boundingRect;
	Rect rcB = rbB.boundingRect;

	Vector3 aUR = rcA.upperRightVertex + *rbA.pos;
	Vector3 aUL = rcA.upperLeftVertex + *rbA.pos;
	Vector3 aLR = rcA.lowerRightVertex + *rbA.pos;
	Vector3 aLL = rcA.lowerLeftVertex + *rbA.pos;
	Vector3 bUR = rcB.upperRightVertex + *rbB.pos;
	Vector3 bUL = rcB.upperLeftVertex + *rbB.pos;
	Vector3 bLR = rcB.lowerRightVertex + *rbB.pos;
	Vector3 bLL = rcB.lowerLeftVertex + *rbB.pos;

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	Vector3 axis1 = aUR - aUL;
	Vector3 axis2 = aUR - aLR;
	Vector3 axis3 = bUL - bLL;
	Vector3 axis4 = bUL - bUR;

	vector<Vector3> axes;
	axes.push_back(axis1);
	axes.push_back(axis2);
	axes.push_back(axis3);
	axes.push_back(axis4);

	for (unsigned int i = 0; i < axes.size(); i++)
	{
		Vector3 aURProj = Vector3::Project(aUR, axes[i]);
		Vector3 aULProj = Vector3::Project(aUL, axes[i]);
		Vector3 aLRProj = Vector3::Project(aLR, axes[i]);
		Vector3 aLLProj = Vector3::Project(aLL, axes[i]);
		Vector3 bURProj = Vector3::Project(bUR, axes[i]);
		Vector3 bULProj = Vector3::Project(bUL, axes[i]);
		Vector3 bLRProj = Vector3::Project(bLR, axes[i]);
		Vector3 bLLProj = Vector3::Project(bLL, axes[i]);

		float aURScalar = Vector3::Dot(aURProj, axes[i]);
		float aULScalar = Vector3::Dot(aULProj, axes[i]);
		float aLRScalar = Vector3::Dot(aLRProj, axes[i]);
		float aLLScalar = Vector3::Dot(aLLProj, axes[i]);
		float bURScalar = Vector3::Dot(bURProj, axes[i]);
		float bULScalar = Vector3::Dot(bULProj, axes[i]);
		float bLRScalar = Vector3::Dot(bLRProj, axes[i]);
		float bLLScalar = Vector3::Dot(bLLProj, axes[i]);

		vector<float> aScalars;
		aScalars.push_back(aURScalar);
		aScalars.push_back(aULScalar);
		aScalars.push_back(aLRScalar);
		aScalars.push_back(aLLScalar);
		aMin = Math::Min(aScalars);
		aMax = Math::Max(aScalars);

		vector<float> bScalars;
		bScalars.push_back(bURScalar);
		bScalars.push_back(bULScalar);
		bScalars.push_back(bLRScalar);
		bScalars.push_back(bLLScalar);
		bMin = Math::Min(bScalars);
		bMax = Math::Max(bScalars);

		if (bMin <= aMax && bMax >= aMin)
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}
*/