#pragma once
#include "Obstacle.h"
class Spikes :
	public Obstacle
{
public:
	Spikes() :Obstacle(Coord(), '*') {}
	Spikes(Coord loc) :Obstacle(loc, '*') {}
	Spikes(const Spikes& cop):Obstacle(cop) {}
	bool collision(Player &p);
};

