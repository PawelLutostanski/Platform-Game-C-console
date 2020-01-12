#pragma once
#include "Obstacle.h"
class Block :
	public Obstacle
{
	public:
	//void player_touch();//don't let go
	Block() :Obstacle(Coord(), -78) {}
	Block(Coord loc) :Obstacle(loc, -78) {}
	Block(const Block &cop) :Obstacle(cop) {}
};

