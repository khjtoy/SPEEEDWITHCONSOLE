#include "Game.h"


int main()
{
	Game game;
	game.Init();

	while (true)
	{
		if (game.GetStart())
		{
			bool isBreak = game.Update();
			if (isBreak)
				break;
		}
	}	
}

