#pragma once
#include "Obstacle.h"
class Finish :
	public Obstacle
{
	bool ifFinished;
public:
	Finish() :Obstacle(Coord(), 176), ifFinished{ 0 } {}
	Finish(Coord loc) :Obstacle(loc, 176),ifFinished { 0 } {}
	Finish(const Finish& cop) :Obstacle(cop), ifFinished{ cop.ifFinished } {}
	
	bool is_Finished();
	bool collision(Player &p, Coord cor);
};

