#pragma once
#include "Obstacle.h"
class Block :
	public Obstacle
{
	public:
	
	Block() :Obstacle(Coord(), 219) {}
	Block(Coord loc) :Obstacle(loc, 219) {}
	Block(const Block &cop) :Obstacle(cop) {}
	bool collision(Player &p, Coord cor);
	
};

