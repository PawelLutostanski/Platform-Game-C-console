#pragma once
#include "MapElement.h"
class Player :
	public MapElement
{
	int lift; //when jump then lift go up some ticks-tick one game loop and don't fall
	bool alreadyJumped;
public:
	Player() :MapElement(Coord(), -79), lift{ 0 }, alreadyJumped{ 0 } {}
	Player(Coord p) :MapElement(p, -79), lift{ 0 }, alreadyJumped{ 0 } {}
	friend std::ostream& operator<<(std::ostream& os, const Player& pl);
	void finish_jump();
	bool show_if_jumped();
	void lift_set();
	int  lift_of_player();
	bool go_left();
	bool go_right();
	bool go_jump();
	bool go_fall();
	void change_coord(Coord c);
	bool check_if_fail(Coord farthest);//player located out of map fails ( 0 x or y coords or greater than values of given point

	
};

