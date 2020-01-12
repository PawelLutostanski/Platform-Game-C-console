#pragma once
#include "MapElement.h"
class Obstacle :
	public MapElement
{
public:
	//virtual void player_touch();
	Obstacle(Coord loc,char c) :MapElement(loc, c) {}
	Obstacle(const Obstacle &o) :MapElement(o) {}
};

