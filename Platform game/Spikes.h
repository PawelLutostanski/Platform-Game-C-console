#pragma once
#include "Obstacle.h"
class Spikes :
	public Obstacle
{
public:
	//void player_touch();//ends game
	Spikes() :Obstacle(Coord(), '*') {}
	Spikes(Coord loc) :Obstacle(loc, '*') {}
	Spikes(const Spikes& cop):Obstacle(cop) {}
};

