#include "Map.h"

using namespace std;
int main()
{
	Map gameMap("map.txt");
	
	cout << gameMap;
	while (gameMap.player_status())
	{
		
		
		if (!gameMap.input())
		{
			break;
		}

	
	}
	Map::move_cursor(Coord{ 0,0 });
	cin.get();
	system("CLS");
	
	cin.get();
}