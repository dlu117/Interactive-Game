#include "GameManager.h"
#include "Crate.h"

#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"


GameManager::GameManager()
{
   
    engine.Initialize("Game!"); // C++11 string literals are constant data
    // In C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*) 

    Sprite crateSprite = Sprite("Assets/Art/crate.png");
    crateSprite.SetScale(0.2f);
    Sprite userSprite = Sprite("Assets/Art/red.png", Vector3(1,1,1)); // INTIIAL POSITION ON FIRST BLOCK 
   
    userSprite.SetScale(0.05f);
    userSprite.MoveTo(Vector3(crateSprite.GetSize()->x * crateSprite.GetScale()->x / 2, (crateSprite.GetSize()->y * crateSprite.GetScale()->y) + userSprite.GetSize()->y * userSprite.GetScale()->y / 2, 0));

    flapper = new Flapper(userSprite);

    StartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    GameoverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    GameoverSprite.SetScale(0.15f);

    LevelWidth = 64;
    LevelHeight = 16;

    state = State::START; // set initial set to start
}


GameManager::~GameManager()
{
  
}

void GameManager::CreateLevel() 
{
    LevelWidth = 64; // arbitary 
    LevelHeight = 14;

    Sprite crateSprite = Sprite("Assets/Art/crate.png");
    crateSprite.SetScale(0.1f);

    TileWidth = crateSprite.GetSize()->x * crateSprite.GetScale()->x;
    TileHeight = crateSprite.GetSize()->y * crateSprite.GetScale()->y;

   
    slevel += L"########........................................................";
    slevel += L"................................................................";
    slevel += L".............#########.................######...................";
    slevel += L"................................................................";
    slevel += L".......................#########................................";
    slevel += L"...#######......................................................";
    slevel += L"......................############..............................";
    slevel += L"................................................................";
    slevel += L"................................................................";
    slevel += L"................................................................";
    slevel += L"...........................................#####................";
    slevel += L"................#####...........................................";
    slevel += L"................................................................";
    slevel += L"..........................######................................";
    slevel += L"................................................................";
    slevel += L".......................................##################.......";

    // Utility Lambdas
    auto GetTile = [&](int x, int y)
    {
        if (x >= 0 && x < LevelWidth && y >= 0 && y < LevelHeight)
            return slevel[y * LevelWidth + x];
        else
            return L' '; //return space
    };

   
    for (int x = 0; x < Engine::SCREEN_WIDTH / TileWidth; x++)
    {
        for (int y = 0; y < Engine::SCREEN_HEIGHT / TileHeight; y++)
        {
            wchar_t sTile = GetTile(x,y);
           
            switch (sTile)
            {
            case L'#':
                
                crateSprite.MoveTo(Vector3(x * TileWidth , y * TileHeight, 1));
                crateSprite.Render();
                break;
            default:
                break;

            }

        }

    }

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
            
           
           // Crate* floorcrate = new Crate(5);
           

            flapper->Render();
            
            CreateLevel();

            /*
            Sprite crateSprite = Sprite("Assets/Art/crate.png");
            crateSprite.SetScale(0.2f);
            crateSprite.MoveTo(Vector3(10 * crateSprite.GetSize()->x * crateSprite.GetScale()->x, 1, 1));
          
            crateSprite.Render();

            Sprite crateSprite1 = Sprite("Assets/Art/crate.png");
            crateSprite1.SetScale(0.2f);
            crateSprite1.MoveTo(Vector3(11 * crateSprite.GetSize()->x * crateSprite.GetScale()->x , 1, 1));
            crateSprite1.Render();

            Sprite crateSprite2 = Sprite("Assets/Art/crate.png");
            crateSprite2.SetScale(0.2f);
            crateSprite2.MoveTo(Vector3(12* crateSprite.GetSize()->x * crateSprite.GetScale()->x , 1, 1));
            crateSprite2.Render();
            */
            
        
            /*
          
            // Draw Level
            int VisibleTilesX = Engine::SCREEN_WIDTH / nTileWidth;
            int VisibleTilesY = Engine::SCREEN_HEIGHT / nTileHeight;

            // Camera represents middle of the screen
            float OffsetX = CameraPosX - (float)VisibleTilesX / 2.0f;
            float OffsetY = CameraPosY - (float)VisibleTilesY / 2.0f;

            // Clamp Camera
            if (OffsetX < 0) OffsetX = 0;
            if (OffsetY < 0) OffsetY = 0;
            if (OffsetX > LevelWidth - VisibleTilesX) OffsetX = LevelWidth - VisibleTilesX;
            if (OffsetY > LevelWidth - VisibleTilesY) OffsetY = LevelWidth - VisibleTilesY;


             */
            
           

            if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            {
                SetState(State::GAMEOVER);
            }

            if (Keyboard::KeyDown(GLFW_KEY_SPACE))
            {
                SetState(State::GAMEPLAY);
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

        case State::GAMEOVER:
        {
            engine.BeginRender();
            GameoverSprite.Render();
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










