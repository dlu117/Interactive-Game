#include "GameManager.h"

#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"


GameManager::GameManager()
{
   
    engine.Initialize("Game!"); // C++11 string literals are constant data
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 


    Sprite testsprite = Sprite("Assets/Art/car1.png", Vector3(Engine::SCREEN_WIDTH / 2, 0, 0));
    testsprite.SetScale(0.20f);

    flapper = new Flapper(testsprite);

    StartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    //GameoverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    GameoverSprite.SetScale(0.15f);

    state = State::START; // set initial set to start
}


GameManager::~GameManager()
{
  
}



void GameManager::Start()
{

    while (true)  // WHILE LOOP CAUSES TEXTURE TO FALL DOWN
    {

        engine.Update();


        switch (state)
        {

        case State::START:
        {
            engine.BeginRender();
            StartSprite.Render();
            engine.EndRender();

            if (Keyboard::KeyDown(GLFW_KEY_SPACE))
            {
                SetState(State::GAMEPLAY);
            }

        }
        break;

        case State::GAMEPLAY:
        {
            flapper->Update();
            
            engine.BeginRender();
            flapper->Render();

            if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) 
            {
                flapper->GetSprite().RotateBy(-100);
            }


            if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT))
            {
                flapper->GetSprite().RotateBy(100);
            }


            if (Keyboard::Key(GLFW_KEY_W) || Keyboard::Key(GLFW_KEY_UP))
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
            engine.EndRender();

        }

        break;

        default:
            cout << "Unhandled game state: " << static_cast<int> (state) << endl;
            break;

        }
    }
}


void GameManager::SetState(State _state)
{
    state = _state;

}










