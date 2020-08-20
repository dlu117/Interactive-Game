#include "GameManager.h"

#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"

GameManager::GameManager(Flapper * _flapper)
{
	flapper = _flapper;
}


void GameManager::Update()
{
    if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))  // left mouse button just pressed
    {
        flapper->GetSprite().RotateBy(100);
    }


    if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
    {
        flapper->GetSprite().RotateBy(-100);
    }


    if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
    {
        flapper->GetSprite().RotateBy(100);
    }

    if (Keyboard::Key(GLFW_KEY_W)|| Keyboard::Key(GLFW_KEY_UP))
    {
        flapper->GetRB().AddForce(Vector3(0, 200, 0));
    }

    if (Keyboard::Key(GLFW_KEY_S) || Keyboard::Key(GLFW_KEY_DOWN))
    {
        flapper->GetRB().AddForce(Vector3(0, -200, 0));
    }

    if (Keyboard::Key(GLFW_KEY_A) || Keyboard::Key(GLFW_KEY_LEFT))
    {
        flapper->GetRB().AddForce(Vector3(-200, 0, 0));
    }

    if (Keyboard::Key(GLFW_KEY_D) || Keyboard::Key(GLFW_KEY_RIGHT))
    {
        flapper->GetRB().AddForce(Vector3(200, 0, 0));
    }

}

