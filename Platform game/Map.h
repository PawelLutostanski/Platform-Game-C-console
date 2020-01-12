#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <list>
#include <cstddef>
#include <iterator> 
#include "MapElement.h"
#include "Block.h"
#include "Spikes.h"
#include "Player.h"

class Map
{

private:
	unsigned int maxX, maxY;
	std::list <Block> blockList;
	std::list <Spikes> spikeList;
	Player user;
	bool doGame;
public:
	enum class Keyboard {
		up0 = 0x57, up1 = VK_SPACE, up2 = VK_UP, down0 = 0x53, down1 = VK_DOWN,
		right0 = 0x44, right1 = VK_RIGHT, left0 = 0x41, left1 = VK_LEFT, esc= VK_ESCAPE
	};
	Map(std::string map_file_name);
	friend std::ostream& operator<<(std::ostream& os, const Map& m);
	friend std::ostream& operator<<(std::ostream& os, std::list <Block> &bl);
	friend std::ostream& operator<<(std::ostream& os, std::list <Spikes> &sl);
	friend std::ostream& operator<<(std::ostream& os, const Player& pl);
//protected:
	bool game_stat() { return doGame; }
	void game_over() { doGame = 0; }
	
	void destroy_element(Coord where_it_is);
	//friend class MapElement;

	static void move_cursor(Coord p)
	{
		COORD cord;
		cord.X = p.x;
		cord.Y = p.y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	}
	

	//void show_user();
	void setup() 
	{
		doGame = true;
	}
	int input();
	static void logic()
	{
	}
};
