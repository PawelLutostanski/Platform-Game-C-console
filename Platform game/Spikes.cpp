#include "Spikes.h"

bool Spikes::collision(Player &p,Coord cor)
{
	Coord temp = cor;
	if (  (location.x == temp.x)  &&  (location.y==temp.y)  )
	{
		p.change_coord(Coord{ 0,0 });//in that field player fails
		return 1;
	}
	return 0;
}