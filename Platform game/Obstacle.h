#pragma once
#include "Player.h"
class Obstacle :
	public MapElement
{
public:
	virtual bool collision(Player &p) {return 1; };
	Obstacle(Coord loc,char c) :MapElement(loc, c) {}
	Obstacle(const Obstacle &o) :MapElement(o) {}
};

