#pragma once

//#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <list>
#include <iterator> 
#include <exception>
#include "Block.h"
#include "Spikes.h"
#include "Player.h"
#include "Finish.h"


struct NoFileException : public std::exception {
	const char * what() const throw () {
		return "Couldn't find file";
	}
};

class Map
{

private:
	Coord limit;
	std::list <Obstacle*> obstList;
	Player user;
	Finish *succes;
public:
	Map(std::string map_file_name);
	~Map();
	


	friend std::ostream& operator<<(std::ostream& os, std::list <Obstacle*> &bl);
	friend std::ostream& operator<<(std::ostream& os, const Map& m);
	
	
	static void move_cursor(Coord p);	
	bool input();
	bool player_status();
	bool finish_status();
	bool collision_with_player(Coord p);
};
