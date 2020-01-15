#include "Player.h"

std::ostream& operator<<(std::ostream& os, const Player& pl)
{
	Player temp(pl);
	char c = temp.show_shape();
	os << c;
	return os;
}
void Player::finish_jump()
{
	alreadyJumped = 0;
	lift = 0;
}
bool Player::show_if_jumped()
{
	return alreadyJumped;
}
void Player::lift_set()
{
	lift = 7;
}
int Player::lift_of_player()
{
	if (lift > 0)
	{ 
		--lift; 
	}
	return lift;
}

bool Player::go_left()
{
	location.x -= 1;
	return 1;
}

bool Player::go_right()
{
	location.x += 1;
	return 1;
}

bool Player::go_jump()
{
	alreadyJumped = 1;
	location.y -= 1;
	return 1;
}
bool Player::go_fall()
{
	location.y += 1;
	return 1;
}

void Player::change_coord(Coord c)
{
	location = c;
}
bool Player::check_if_fail(Coord farthest)
{
	if (location.x == 0 || location.y == 0 || location.x > farthest.x || location.y > farthest.y)
	{
		return  1; //fails
	}
	return 0;//lives

}