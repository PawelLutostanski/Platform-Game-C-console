#pragma once

struct Coord
{
	unsigned int x, y;
	Coord() :x{ 0 }, y{ 0 }{}
	Coord(unsigned int xval, unsigned int yval) :x{ xval }, y{ yval }{}
};
