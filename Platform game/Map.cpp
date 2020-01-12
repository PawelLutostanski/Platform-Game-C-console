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

int Map::input()
{
	int pulses = 1000;
	for (int i = 0; i < pulses; i++) 
	{
		if (GetAsyncKeyState(static_cast<int>(Keyboard::up0)) != 0 || GetAsyncKeyState(static_cast<int>(Keyboard::up1)) != 0 || //enum is  strongly typed var 
			GetAsyncKeyState(static_cast<int>(Keyboard::up2)) != 0)
		{
			user.go_jump();
			break;
		}
		else if (GetAsyncKeyState(static_cast<int>(Keyboard::down0)) != 0 || GetAsyncKeyState(static_cast<int>(Keyboard::down1)) != 0)
		{
			user.go_fall();
			break;
		}
		else if (GetAsyncKeyState(static_cast<int>(Keyboard::right0)) != 0 || GetAsyncKeyState(static_cast<int>(Keyboard::right1)) != 0)
		{
			user.go_right();
			break;
		}
		else if (GetAsyncKeyState(static_cast<int>(Keyboard::left0)) != 0 || GetAsyncKeyState(static_cast<int>(Keyboard::left1)) != 0)
		{
			user.go_left();
			break;
		}
		else if (GetAsyncKeyState(static_cast<int>(Keyboard::esc)))
		{
			return 0;
		}
		Sleep(100);
		std::cout << user;
	}
	return 1;
}
