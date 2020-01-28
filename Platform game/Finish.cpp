#include "Finish.h"

bool Finish::is_Finished()
{
	return ifFinished;
}

bool Finish::collision(Player&p,Coord cor)
{
	if ((location.x == cor.x) && (location.y == cor.y))
	{
		ifFinished = 1;
	}
	return ifFinished;
}