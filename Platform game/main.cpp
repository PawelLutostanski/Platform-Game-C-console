#include "Map.h"

using namespace std;
int main()
{
	Map gameMap("map.txt");
	gameMap.setup();
	cin.get();
	cout << gameMap;
	while (gameMap.game_stat())
	{
		if (!gameMap.input())
		{
			gameMap.game_over();
		}
	}
	cin.get();
	system("CLS");
	
	cin.get();
}