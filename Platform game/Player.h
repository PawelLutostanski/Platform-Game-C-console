#pragma once
#include "MapElement.h"
class Player :
	public MapElement
{
	short int fly; //when jump then flies go up some ticks-tick one game loop and don't fall
public:
	void collision();
	void go_left()
	{
		location.x -= 1;
	}
	void go_right()
	{
		location.x += 1;
	}
	void go_jump()
	{
		location.y -= 1;
	}
	void go_fall()
	{
		location.y -= 1;
	}
	Player():MapElement(Coord(), -79) {}
	Player(Coord p) :MapElement(p, -79) {}
	
};

