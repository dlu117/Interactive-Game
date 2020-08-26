#include "Crate.h"


Crate::~Crate()   
{

	
}



Sprite* Crate::crateSprite = NULL;



Crate::Crate()   // CREATES 1 CRATE
{
	crateSprite = new Sprite("Assets/Art/crate.png");
	crateSprite->SetScale(0.2f);
	int x = crateSprite->GetSize()->x * crateSprite->GetScale()->x / 2;
	int y = crateSprite->GetSize()->y * crateSprite->GetScale()->y / 2;

	crateSprite->MoveTo(Vector3(x, y, 0));
	crateSprite->Render();

}


Crate::Crate(int n):Crate() // CREATES N CRATES
{

	for (int i = 1; i < n; i++) {

		crateSprite->MoveTo(Vector3((2 * i + 1) * crateSprite->GetSize()->x * crateSprite->GetScale()->x / 2, crateSprite->GetSize()->y * crateSprite->GetScale()->y / 2, 0));
		crateSprite->Render();

	}

}