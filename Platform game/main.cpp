#include "Map.h"

using namespace std;
int main()
{
	Map gameMap("map.txt");
	
	cout << gameMap;
	while (gameMap.player_status())
	{
		char key = NULL;
		if (_kbhit())
		{
			(key = _getch());
		}
		
		if (!gameMap.input(key))
		{
			break;
		}

	
	}
	Map::move_cursor(Coord{ 0,0 });
	cin.get();
	system("CLS");
	
	cin.get();
}