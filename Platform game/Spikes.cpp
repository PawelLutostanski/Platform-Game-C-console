#include "Spikes.h"

bool Spikes::collision(Player &p)
{
	Coord temp = p.show_loc();
	if (  (location.x == temp.x)  &&  (location.y==temp.y)  )
	{
		p.change_coord(Coord{ 0,0 });//in that field player fails
		return 1;
	}
	return 0;
}