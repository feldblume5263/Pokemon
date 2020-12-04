#include "map.h"

void		Map::relocate_p(MyPlayer *p, int x, int y)
{
	int		row;
	int		col;

	row = -1;
	while (++row < this->pokemon_map.size())
	{
		col = -1;
		while (++col < this->pokemon_map[row].size())
		{
			if (this->pokemon_map[row][col] == (this->pre_f + 'A' - 1))
			{
				if (x > 100)
					p->SetPos(col + 2, y);
				else
					p->SetPos(col - 2, y);
				if (y > 32)
					p->SetPos(p->GetPos().x, row + 2);
				else
					p->SetPos(p->GetPos().x, row - 2);
				return ;
			}
		}
	}
}

void		Map::delete_pre_map()
{
	this->pokemon_map.erase(this->pokemon_map.begin(), this->pokemon_map.end());
}

void			Map::change_map(MyPlayer *p, char *path, int open_flag, int x, int y)
{
	string		buffer;
	ifstream	map_file;
	char		temp[1000];
	char		num[2];

	if (open_flag == 0)
		return ;
	this->delete_pre_map();
	this->pre_f = this->cur_f;
	this->cur_f = open_flag;
	strcpy(temp, path);
	num[0] = open_flag + 'A' - 1;
	num[1] = '\0';
	strcat(temp, num);
	cout << temp << endl;
	map_file.open(temp);
	while (map_file.peek() != EOF)
	{
		getline(map_file, buffer);
		this->set_map_line(buffer);
	}
	relocate_p(p, x, y);
}

int			Map::find_door(int x, int y, MyPlayer *p)
{
	if (this->pokemon_map[y - 1][x] <= 'Y' && this->pokemon_map[y - 1][x] >= 'A')
		return (this->pokemon_map[y - 1][x] - 'A' + 1);
	else if (this->pokemon_map[y + 1][x] <= 'Y' && this->pokemon_map[y + 1][x] >= 'A')
		return (this->pokemon_map[y + 1][x] - 'A' + 1);
	else if (this->pokemon_map[y][x - 1] <= 'Y' && this->pokemon_map[y][x - 1] >= 'A')
		return (this->pokemon_map[y][x - 1] - 'A' + 1);
	else if (this->pokemon_map[y][x + 1] <= 'Y' && this->pokemon_map[y][x + 1] >= 'A')
		return (this->pokemon_map[y][x + 1] - 'A' + 1);
	if (this->pokemon_map[y - 1][x] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[y + 1][x] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[y][x - 1] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[y][x + 1] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(p);
		cout << "\a" << endl;
	}
	return (0);
}

void		Map::handle_key(int key, int x, int y, MyPlayer *p, OtherPlayer *o)
{
	if (key == M_KEY_UP)
	{
		this->pokemon_map[y][x] = ' ';
		if (this->pokemon_map[y - 1][x] == ' ' && this->pokemon_map[y - 1][x])
			p->SetPos(x, y - 1);
	}
	else if (key == M_KEY_DOWN)
	{
		this->pokemon_map[y][x] = ' ';
		if (this->pokemon_map[y + 1][x] == ' ' && this->pokemon_map[y + 1][x])
			p->SetPos(x, y + 1);
	}
	else if (key == M_KEY_RIGHT)
	{
		this->pokemon_map[y][x] = ' ';
		if (this->pokemon_map[y][x + 1] == ' ' && this->pokemon_map[y][x + 1])
			p->SetPos(x + 1, y);
	}
	else if (key == M_KEY_LEFT)
	{
		this->pokemon_map[y][x] = ' ';
		if (this->pokemon_map[y][x - 1] == ' ' && this->pokemon_map[y][x - 1] == ' ')
			p->SetPos(x - 1, y);
	}
	else if (key == M_KEY_SPACE)
	{
		if (this->pokemon_map[y - 1][x] <= '9' && this->pokemon_map[y - 1][x] >= '1')
			Battle(p, o);
		else if (this->pokemon_map[y + 1][x] <= '9' && this->pokemon_map[y + 1][x] >= '1')
			Battle(p, o);
		else if (this->pokemon_map[y][x - 1] <= '9' && this->pokemon_map[y][x - 1] >= '1')
			Battle(p, o);
		else if (this->pokemon_map[y][x + 1] <= '9' && this->pokemon_map[y][x + 1] >= '1')
			Battle(p, o);
	}
	else if (key == M_KEY_ESC)
	{
		exit(0);
	}
	else
		return ;
}

void		Map::draw_map()
{
	vector<string>	p_map;
	int				idx;

	idx = 0;
	p_map = this->get_map_file();
	idx = 0;
	while (idx < p_map.size())
	{
		cout << p_map[idx] << endl;
		idx++;
	}
}

void		Map::draw_player(int x, int y)
{
	this->pokemon_map[y][x] = 'O';
}

int			Map::noah_getch()
{
	struct	termios oldt;
	struct	termios newt;
	int		ch;

	tcgetattr( STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO);
	tcsetattr( STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
	return (ch);
}

int				Map::check_valid(int argc, char *file_path)
{
	int			idx;
	char		*temp;

	if (argc == 2)
	{
		idx = 0;
		while (file_path[idx])
			idx++;
		if (file_path[--idx] != '/')
		{
			file_path = strcat(file_path, "/");
		}
		return (TRUE);
	}
	else
	{
		cout << "please compile with pokemon version folder" << endl;
		return (ERROR);
	}
}

vector<string> Map::get_map_file()
{
	return (this->pokemon_map);
}

void			Map::set_map_line(std::string string)
{
	this->pokemon_map.push_back(string);
}

void			Map::first_set_map_file(int argc, char *file_path)
{
	string		buffer;
	ifstream	map_file;
	char		temp[1000];

	this->cur_f = 1;
	this->pre_f = 0;
	if (!(this->check_valid(argc, file_path)))
		exit(0);
	strcpy(temp, file_path);
	strcat(temp, "A");
	map_file.open(temp);
	if (!(map_file.is_open()))
	{
		cout << "file_error\n" << endl;
		exit(0);
	}
	while (map_file.peek() != EOF)
	{
		getline(map_file, buffer);
		this->set_map_line(buffer);
	}
}

// int				main(int argc, char *argv[])
// {
// 	Map			map;
// 	int			idx;
// 	// char		path[] = "../gold_version";

// 	int flag = 0;

// 	MyPlayer my_player;
// 	OtherPlayer other_player;
// 	my_player.SetPokemon();
// 	my_player.SetPokemon();
// 	other_player.SetPokemon();
// 	other_player.SetPokemon();
// 	my_player.SetPos(99, 6);
// 	map.first_set_map_file(argc, argv[1]);
// 	system("printf '\e[8;100;200t'");
// 	system("clear");
// 	while (1)
// 	{
// 		map.draw_player(my_player.GetPos().x, my_player.GetPos().y);
// 		map.draw_map();
// 		map.handle_key(map.noah_getch(), my_player.GetPos().x, my_player.GetPos().y, &my_player, &other_player);
// 		map.change_map(&my_player, argv[1], map.find_door(my_player.GetPos().x, my_player.GetPos().y, &my_player), my_player.GetPos().x, my_player.GetPos().y);
// 		system("clear");
// 	}
// 	return (0);
// }
