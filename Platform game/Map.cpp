#include <exception>
#include <conio.h>
#include "Map.h"


struct NoFileException : public std::exception {
	const char * what() const throw () {
		return "No \"map.txt\" file found";
	}
};

Map::Map(std::string mapFileName):maxX{0},maxY{0},doGame{1}
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
						spikeList.push_back(temp);
					}
				}
				else
				{

					j++;
					if (maxX < i) { maxX = i; }
					i = 0;
				}
				i++;

			}
			maxY = j;
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
/*
template <class T>
std::ostream& operator<<(std::ostream& os, const std::list <T> &bl)
{
	std::list<T> copyL(bl);//required because bl const
	std::list <Block>::iterator it;
	for (it = copyL.begin(); it != copyL.end(); ++it)
	{
		Map::move_cursor(it->show_loc());
		os << it->show_shape();
	}
	return os;
}*/
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
	os << m.spikeList;
	unsigned int mx = m.maxX+5;
	unsigned int my = m.maxY+5;
	Coord p{ mx,my };
	Map::move_cursor(p);//put cursor away
	//Map::move_cursor(r);
	return os;
}
std::ostream& operator<<(std::ostream& os, const Player& pl)
{
	Player temp(pl);
	Map::move_cursor(temp.show_loc());
	char c = temp.show_shape();
	os << c;
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
		if (key=='w' || key=='W'|| key==' '||key==72)
		{
			user.go_jump();
		}
		else if (key == 's' || key == 'S' )
		{
			//user.go_fall();
		}
		else if (key == 'd' || key == 'D' || key == 77)
		{
			user.go_right();
		}
		else if (key == 'a' || key == 'A'||key == 75)
		{
			user.go_left();
		}
		else if (key == 27)
		{
			return 0;
		}
		std::cout << user;
		Sleep(100);
	return 1;
}
