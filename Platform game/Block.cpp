#include "Block.h"

bool Block::collision(Player &p, Coord cor)
{
	if ((cor.x == location.x) && (cor.y == location.y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}