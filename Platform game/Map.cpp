#include <exception>
#include <conio.h>
#include "Map.h"


struct NoFileException : public std::exception {
	const char * what() const throw () {
		return "No \"map.txt\" file found";
	}
};

Map::Map(std::string mapFileName) :limit{ Coord{0,0} }
{
	try {
		std::ifstream mapFile;
		mapFile.open(mapFileName);
		//spikeList = new std::list<Spikes>;
		if (mapFile.good())
		{
			char c;
			unsigned int i{ 1 }, j{ 1 };
			Coord whereNow{ 0, 0};
			bool findPlayer{ 0 }, findFinish{ 0 };
			while (mapFile.get(c))
			{
				
				//std::cout << c;//debug
				if (c != '\n' && c != NULL)
				{
					Coord temp{ i,j };
					whereNow = temp;
					if ((c == 'P' || c == 'p')&&!findPlayer)
					{
						findPlayer = 1;
						Player p(temp);
						user=p;
					}
					if (c == '#' || c == '3')
					{
						blockList.push_back(temp);
					}
					if (c == '*' || c == '8')
					{
						spikesList.push_back(temp);
					}
				}
				else
				{

					j++;
					if (limit.x < i) { limit.x = i; }
					i = 0;
				}
				i++;

			}
			limit.y = j;
			mapFile.close();
		}
		else {
			throw NoFileException();
		}
	}
	catch (NoFileException error)
	{
		std::cin.get();
		return;
	}
}

std::ostream& operator<<(std::ostream& os,const std::list <Block> &bl)
{
	std::list<Block> copyL(bl);//required because bl const
	std::list <Block>::iterator it;
	for (it = copyL.begin(); it != copyL.end(); ++it)
	{
		Map::move_cursor(it->show_loc());
		os << it->show_shape();
	}
	return os;
}

std::ostream& operator<<(std::ostream& os,const std::list <Spikes> &sl)
{
	std::list<Spikes> copyL(sl);//required because sl const
	std::list <Spikes>::iterator it;
	for (it = copyL.begin(); it != copyL.end(); ++it)
	{
		Map::move_cursor(it->show_loc());
		os << it->show_shape();
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Map& m)
{
	os << m.blockList;
	os << m.spikesList;

	Map::move_cursor(Coord{ m.limit.x+5,m.limit.y+5 });//put cursor away
	return os;
}

void Map::move_cursor(Coord p)
{
	COORD cord;
	cord.X = p.x;
	cord.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

int Map::input(char key)
{
	
	Coord temp(user.show_loc());
	move_cursor(temp);
	std::cout << ' ';
	if (user.lift_of_player() > 0)
	{
		temp.y -= 1;
		if (col_with_spikes(temp)) { return 0; }
		if (!col_with_blocks(temp))
		{
			user.go_jump();
		}
		else
		{
			temp.y += 1;
		}
	}
		if (key=='w' || key=='W'|| key==' '||key==72)
		{
			temp.y -= 1;
			if (col_with_spikes(temp)) { return 0; }
			if (!col_with_blocks(temp))
			{
				
				if (user.lift_of_player() == 0)
				{
					user.go_jump();
				}
				user.lift_set();
			}
			else 
			{
				temp.y += 1;
			}
		}
		else if (key == 's' || key == 'S' )
		{
			/*temp.y += 1;
			if (col_with_spikes(temp)) { return 0; }
			if (!col_with_blocks(temp))
			{
				user.go_fall();
			}*/
		}
		else if (key == 'd' || key == 'D' || key == 77)
		{
			temp.x += 1;
			if (col_with_spikes(temp)) { return 0; }
			if (!col_with_blocks(temp))
			{
				user.go_right();
			}	
			else
			{
				temp.x -= 1;
			}
		}
		else if (key == 'a' || key == 'A'||key == 75)
		{
			temp.x -= 1;
			if (col_with_spikes(temp)) { return 0; }
			if (!col_with_blocks(temp))
			{
				user.go_left();
			}
			else
			{
				temp.x += 1;
			}
			
		}
		else if (key == 27)
		{
			temp.x -= 1;
			col_with_spikes(temp);
			return 0;
		}
		if (user.lift_of_player() == 0)
		{
			temp.y += 1;
			if (col_with_spikes(temp)) { return 0; }
			if (!col_with_blocks(temp))
			{
				user.go_fall();
			}
			else
			{
				temp.y -= 1;
			}
		}
		

		Map::move_cursor(user.show_loc());
		std::cout << user;
	
		Map::move_cursor(Coord{ limit.x + 5,limit.y + 5 });//put cursor away
		Sleep(100);

	return 1;
}

bool Map::player_status()
{
	if (user.check_if_fail(limit)) { return 0; }//he fails
	return 1;
}

bool Map::col_with_spikes(Coord p)
{
	std::list <Spikes>::iterator it;
	for (it = spikesList.begin(); it != spikesList.end(); ++it)
	{
		if (it->location.x == p.x && it->location.y == p.y)
		{
			return 1;
		}
	}
	return 0;
}

bool Map::col_with_blocks(Coord p)
{
	std::list <Block>::iterator it;
	for (it = blockList.begin(); it != blockList.end(); ++it)
	{
		if (it->location.x == p.x && it->location.y == p.y)
		{
			return 1;
		}
	}
	return 0;
}