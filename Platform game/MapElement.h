#pragma once
struct Coord
{
	unsigned int x, y;
	Coord() :x{0},y{0}{}
	Coord(unsigned int xval,unsigned int yval):x{xval},y{yval}{}
};

class MapElement//abstract class
{
protected:
	Coord location;
	char shape;
public:
	MapElement() :location(), shape('?') {}//? because MapElement is abstract class if it appear on map then something is wrong
	MapElement(Coord loc) :location(loc), shape('?') {}
	MapElement(Coord loc, char c):location(loc), shape(c){}
	MapElement(const MapElement& me) :location(me.location), shape(me.shape) {};
	Coord show_loc() { return location; }
	char show_shape() { return shape; }
	void put_on_map(Coord);
	void erase();
	void change_loc(Coord);
	friend class Map;
};

