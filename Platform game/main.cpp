#include "Map.h"

using namespace std;
int main()
{
	
	cout << "Please make sure that You fullsreen before playing\n Press enter to continue\n";
	while (!GetAsyncKeyState(VK_RETURN)) {}//wait to pressing enter 
	string mapName = "map";
	system("CLS");
	bool wonAll{ 1 };
	for (int i = 1; 1; i++)
	{
		string mapbuff = mapName + static_cast<char>(i + 48) + ".txt";
		fstream test;
		test.open(mapbuff, ios::in);
		if (!test.good()) { break; }
		Map gameMap(mapbuff);
		cout << gameMap;
		while (gameMap.player_status() && !gameMap.finish_status())
		{
			if (!gameMap.input())
			{
				break;
			}
		}
		system("CLS");
		if (gameMap.finish_status() == 0)
		{
			char c;
			cout << "You failed.\n Do you want to try again? Type Y if you want to try again or anything else to exit game." << endl;
			Sleep(500);
			cin >> c;
			if (!(c == 'y' || c == 'Y'))//Y key
			{
				wonAll = 0;
				break;
			}
			else {
				i--;
				system("CLS");
			}
		}
	}
	if (wonAll) { cout << "You won\n" << endl; }
	cout << "Press enter to exit\n";
	while (!GetAsyncKeyState(VK_RETURN)) {}
}