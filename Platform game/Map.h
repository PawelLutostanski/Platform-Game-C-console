#pragma once

//#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
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
	Coord limit;
	std::list <Block> blockList;
	std::list <Spikes> spikesList;
	Player user;
public:
	Map(std::string map_file_name);
	

	/*template <class T>
	friend std::ostream& operator<<(std::ostream& os, const std::list <T> &bl)
	{
		
		std::list<T> copyL(bl);//required because bl const
		std::list <T>::iterator it;
		for (it = copyL.begin(); it != copyL.end(); ++it)
		{
			Map::move_cursor(it->show_loc());
			os << it->show_shape();
		}
		return os;
		
	}*/
	friend std::ostream& operator<<(std::ostream& os, std::list <Block> &bl);
	friend std::ostream& operator<<(std::ostream& os, std::list <Spikes> &sl);
	friend std::ostream& operator<<(std::ostream& os, const Map& m);
	
	
	static void move_cursor(Coord p);
	
	//void show_user();
	
	bool input();
	bool player_status();
	bool col_with_spikes(Coord p);
	bool col_with_blocks(Coord p);
};
