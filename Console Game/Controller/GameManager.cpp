#include "GameManager.h"
#include "Crate.h"

#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"


GameManager::GameManager()
{
   
    engine.Initialize("Game!"); // C++11 string literals are constant data  // C++11 you can no longer assign a string literal directly to a pointer-to-non-const-char (char*)
    
    Sprite userSprite = Sprite("Assets/Art/red.png", Vector3(100,100,1)); 
    userSprite.SetScale(0.05f);
    flapper = new Flapper(userSprite);

    StartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    GameoverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
    GameoverSprite.SetScale(0.15f);

    LevelWidth = 64;
    LevelHeight = 16;

    state = State::START; 
}


GameManager::~GameManager()
{
  
}

void GameManager::CreateLevel() 
{
    LevelWidth = 64; 
    LevelHeight = 14;

    Sprite crateSprite = Sprite("Assets/Art/crate.png");
    crateSprite.SetScale(0.1f);

    
    TileWidth = crateSprite.GetSize()->x * crateSprite.GetScale()->x;  
    TileHeight = crateSprite.GetSize()->y * crateSprite.GetScale()->y;


    // Draw Level
    int VisibleTilesX = Engine::SCREEN_WIDTH / TileWidth;
    int VisibleTilesY = Engine::SCREEN_HEIGHT / TileHeight;

    // "."  represents empty tile position
    // "#"  represents  position of a tile
    slevel += L"................................................................";
    slevel += L"................................................................";
    slevel += L"..........................###########...........................";
    slevel += L"........................###..................###................";
    slevel += L"......###.............###....................###................";
    slevel += L"....................###.........................................";
    slevel += L"..................####..........................................";
    slevel += L"#########################################.######################";
    slevel += L"........................................#.#.....................";
    slevel += L"........................################..#.....................";
    slevel += L"........................#.................#.....................";
    slevel += L"........................###################.....................";
    slevel += L"........................#.......................................";
    slevel += L"........................###################.....................";
    slevel += L"................................................................";
    slevel += L"................................................................";
    slevel += L"................................................................";



    // 
    auto GetTile = [&](int x, int y)
    {
        if (x >= 0 && x < LevelWidth && y >= 0 && y < LevelHeight)
            return slevel[x + y * LevelWidth];
        else
            return L' '; 
    };

    

    // Camera/User represents middle of the screen
     
    float OffsetX = CameraPosX - (float)VisibleTilesX / 2.0f;
    float OffsetY = CameraPosY - (float)VisibleTilesY / 2.0f;

    
    // Clamp Camera to game boundaries
    if (OffsetX < 0) OffsetX = 0;
    if (OffsetY < 0) OffsetY = 0;

    if (OffsetX > LevelWidth * TileWidth - VisibleTilesX) OffsetX = LevelWidth * TileWidth - VisibleTilesX;
    if (OffsetY > LevelWidth * TileHeight - VisibleTilesY) OffsetY = LevelWidth * TileHeight - VisibleTilesY;

  

    // Draw visible tile map
      // offset moves us further into the 2d array
    for (int x = 0; x < VisibleTilesX; x++)
    {
        for (int y = 0; y < VisibleTilesY; y++)
        {
            wchar_t sTile = GetTile(x + OffsetX, y + OffsetY);
           
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
 
  

    while (true) 
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
                SetPlayerPos();
              
    
            }

            if (Keyboard::Key(GLFW_KEY_S) || Keyboard::Key(GLFW_KEY_DOWN))
            {
                flapper->GetRB().AddForce(Vector3(0, -200, 0));
                SetPlayerPos();
                
            }

            if (Keyboard::Key(GLFW_KEY_A) || Keyboard::Key(GLFW_KEY_LEFT))
            {
                flapper->GetRB().AddForce(Vector3(-200, 0, 0));
                SetPlayerPos();
               
            }

            if (Keyboard::Key(GLFW_KEY_D) || Keyboard::Key(GLFW_KEY_RIGHT))
            {
                flapper->GetRB().AddForce(Vector3(200, 0, 0));
                SetPlayerPos();
                
                
            
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


void GameManager::SetPlayerPos()
{    
  
    CameraPosX = flapper->GetSprite().GetPos()->x;
    CameraPosX = flapper->GetSprite().GetPos()->y;
   
    
}









