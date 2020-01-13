#include "Map.h"

using namespace std;
int main()
{
	Map gameMap("map.txt");
	gameMap.setup();
	
	cout << gameMap;
	while (gameMap.game_stat())
	{
		char key = NULL;
		if (_kbhit())
		{
			(key = _getch());
		}
		
		if (!gameMap.input(key))
		{
			gameMap.game_over();
		}
	}
	cin.get();
	system("CLS");
	
	cin.get();
}