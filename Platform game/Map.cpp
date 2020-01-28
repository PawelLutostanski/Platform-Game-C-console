#include "Map.h"


Map::Map(std::string mapFileName) :limit{ Coord{0,0} }, user{ { Coord{0,0} } }//user is 0 because if not find then fails map imediatelly
{
	try {
		std::ifstream mapFile;
		mapFile.open(mapFileName);
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
					if ((c == 'P'||c=='p')&&!findPlayer)
					{
						findPlayer = 1;
						Player p(temp);
						user=p;
					}
					if (c == '#')
					{
						Block* temporary = new Block(temp);
						Obstacle *ptr = temporary;
						obstList.push_back(ptr);
					}
					if (c == '*')
					{
						Spikes* temporary = new Spikes(temp);
						Obstacle *ptr = temporary;
						obstList.push_back(ptr);
					}
					if ((c == 'F'||c=='f') && !findFinish)
					{
						findFinish = 1;
						succes = new Finish(temp);
						Obstacle *ptr = succes;
						obstList.push_back(ptr);
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
		Map::move_cursor(Coord(0, 0));
		std::cout <<"No file found please press enter";
		while (!GetAsyncKeyState(VK_RETURN)) {}//till enter press
		return;
	}
}

Map::~Map()
{
	for (auto&& obst : obstList)					//deleting pointers allocated in list
	{
		delete obst;
	}
	obstList.clear();
													//First *succes is part of list so it is already deleted
}

std::ostream& operator<<(std::ostream& os,const std::list <Obstacle*> &bl)
{
	std::list<Obstacle*> copyL(bl);//required because bl const
	std::list<Obstacle*>::iterator it;
	for (it = copyL.begin(); it != copyL.end(); ++it)
	{
		Map::move_cursor((*it)->show_loc());
		os << (*it)->show_shape();
	}
	return os;
}


std::ostream& operator<<(std::ostream& os, const Map& m)
{
	os << m.obstList;
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

bool Map::input()
{
	
	Coord temp(user.show_loc());
	move_cursor(temp);
	std::cout << ' ';//clears place where player was
	if (user.lift_of_player() > 0)
	{
		
		temp.y -= 1;
		if (!collision_with_player(temp)) 
		{ 
			user.go_jump();
		}
		else
		{
			temp.y += 1;
		}
	}
	if (((GetAsyncKeyState(VK_UP)|| GetAsyncKeyState(0x57) || GetAsyncKeyState(VK_SPACE))&& user.lift_of_player()==0)&&user.show_if_jumped()==0)//arrow up or w or space
	{
		temp.y -= 1;
		if (!collision_with_player(temp))
		{
			if (user.lift_of_player() == 0)
			{
					user.go_jump();
			}
				user.lift_set();
		}
		else //if collision then coord shouldn't change
		{
			temp.y += 1;	
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44))//arrow right or d
	{
		temp.x += 1;
		if (!collision_with_player(temp))
		{
			user.go_right();
		}	
		else //if collision then coord shouldn't change
		{
			temp.x -= 1;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41))//arrow left or a
	{
		temp.x -= 1;
		if (!collision_with_player(temp))
		{
			user.go_left();
		}
		else //if collision then coord shouldn't change
		{
			temp.x += 1;
		}	
	}
	if (GetAsyncKeyState(VK_ESCAPE))
	{
			temp.x = 0;
			temp.y = 0;
			return 0;
	}


	if (user.lift_of_player() == 0)//checks if player is not jumping and does gravity
	{
		temp.y += 1;
		if (!collision_with_player(temp))
		{
				user.go_fall();
		}
		else
		{
			user.finish_jump();//if bellow is 
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
bool Map::finish_status()
{
	
	return succes->is_Finished();
}

bool Map::collision_with_player(Coord p)
{
	std::list <Obstacle*>::iterator it;
	for (it = obstList.begin(); it != obstList.end(); ++it)
	{
		if((*it)->collision(user,p))
		{
			return 1;
		}
	}
	return 0;
}

