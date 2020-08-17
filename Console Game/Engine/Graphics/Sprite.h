#ifndef SPRITE
#define SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

// displays texture at a certain location

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos); //float _xpos, float y_pos

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);
	
	//void MoveTo(float x, float y);
	//void MoveBy(float x, float y);
	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);
	
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	
	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x); // dont want to create a vector 3 just to create a single value
	// void SetScale(float x, float y);
	void SetScale(Vector3 v);
	

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();



private:
	Texture texture;
	float speed;
	
	//float xpos;
	//float ypos;
	Vector3 pos;
	
	float rot; //rotation
	
	//float xScale;
	//float yScale;
	Vector3 scale;
	Vector3 size;
};

#endif