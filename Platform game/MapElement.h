#pragma once
#include <iostream>
#include "Coord.h"

class MapElement//abstract class
{
protected:
	Coord location;
	char shape;
public:
	MapElement() :location(), shape('?') {}//? because MapElement is abstract class if it appear on map then something is wrong PS it never appears
	MapElement(Coord loc) :location(loc), shape('?') {}
	MapElement(Coord loc, char c):location(loc), shape(c){}
	MapElement(const MapElement& me) :location(me.location), shape(me.shape) {};
	Coord show_loc() { return location; }
	char show_shape() { return shape; }
};

