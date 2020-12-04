#include "map.h"

void		map::relocate_p(int *x, int *y)
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
				if (*x > 100)
					*x = col + 2;
				else
					*x = col - 2;
				if (*y > 32)
					*y = row + 2;
				else
					*y = row - 2;
				return ;
			}
		}
	}
}

void		map::delete_pre_map()
{
	this->pokemon_map.erase(this->pokemon_map.begin(), this->pokemon_map.end());
}

void			map::change_map(char *path, int open_flag, int *x, int *y)
{
	string		buffer;
	ifstream	map_file;
	char		*temp;
	char		num[2];

	if (open_flag == 0)
		return ;
	this->delete_pre_map();
	this->pre_f = this->cur_f;
	this->cur_f = open_flag;
	temp = strdup(path);
	num[0] = open_flag + 'A' - 1;
	num[1] = '\0';
	temp = strcat(temp, num);
	cout << temp << endl;
	map_file.open(temp);
	while (map_file.peek() != EOF)
	{
		getline(map_file, buffer);
		this->set_map_line(buffer);
	}
	free(temp);
	relocate_p(x, y);
}

int			map::find_door(int *x, int *y, MyPlayer p)
{
	if (this->pokemon_map[*y - 1][*x] <= 'Y' && this->pokemon_map[*y - 1][*x] >= 'A')
		return (this->pokemon_map[*y - 1][*x] - 'A' + 1);
	else if (this->pokemon_map[*y + 1][*x] <= 'Y' && this->pokemon_map[*y + 1][*x] >= 'A')
		return (this->pokemon_map[*y + 1][*x] - 'A' + 1);
	else if (this->pokemon_map[*y][*x - 1] <= 'Y' && this->pokemon_map[*y][*x - 1] >= 'A')
		return (this->pokemon_map[*y][*x - 1] - 'A' + 1);
	else if (this->pokemon_map[*y][*x + 1] <= 'Y' && this->pokemon_map[*y][*x + 1] >= 'A')
		return (this->pokemon_map[*y][*x + 1] - 'A' + 1);
	if (this->pokemon_map[*y - 1][*x] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(&p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[*y + 1][*x] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(&p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[*y][*x - 1] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(&p);
		cout << "\a" << endl;
	}
	else if (this->pokemon_map[*y][*x + 1] == 'Z')
	{
		cout << "\a" << endl;
		Battle battle(&p);
		cout << "\a" << endl;
	}
	return (0);
}

void		map::handle_key(int key, int *x, int *y, MyPlayer p, OtherPlayer o)
{
	if (key == M_KEY_UP)
	{
		this->pokemon_map[*y][*x] = ' ';
		if (this->pokemon_map[*y - 1][*x] == ' ' && this->pokemon_map[*y - 1][*x])
			*y = *y - 1;
	}
	else if (key == M_KEY_DOWN)
	{
		this->pokemon_map[*y][*x] = ' ';
		if (this->pokemon_map[*y + 1][*x] == ' ' && this->pokemon_map[*y + 1][*x])
			*y = *y + 1;
	}
	else if (key == M_KEY_RIGHT)
	{
		this->pokemon_map[*y][*x] = ' ';
		if (this->pokemon_map[*y][*x + 1] == ' ' && this->pokemon_map[*y][*x + 1])
			*x = *x + 1;
	}
	else if (key == M_KEY_LEFT)
	{
		this->pokemon_map[*y][*x] = ' ';
		if (this->pokemon_map[*y][*x - 1] == ' ' && this->pokemon_map[*y][*x - 1] == ' ')
			*x = *x - 1;
	}
	else if (key == M_KEY_SPACE)
	{
	if (this->pokemon_map[*y - 1][*x] <= '9' && this->pokemon_map[*y - 1][*x] >= '1')
		Battle(&p, &o);
	else if (this->pokemon_map[*y + 1][*x] <= '9' && this->pokemon_map[*y + 1][*x] >= '1')
		Battle(&p, &o);
	else if (this->pokemon_map[*y][*x - 1] <= '9' && this->pokemon_map[*y][*x - 1] >= '1')
		Battle(&p, &o);
	else if (this->pokemon_map[*y][*x + 1] <= '9' && this->pokemon_map[*y][*x + 1] >= '1')
		Battle(&p, &o);
	}
	else if (key == M_KEY_ESC)
	{
		exit(0);
	}
	else
		return ;
}

void		map::draw_map()
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

void		map::draw_player(int x, int y)
{
	this->pokemon_map[y][x] = 'O';
}

int			map::noah_getch()
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

int				map::check_valid(int argc, char *file_path)
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

vector<string> map::get_map_file()
{
	return (this->pokemon_map);
}

void			map::set_map_line(std::string string)
{
	this->pokemon_map.push_back(string);
}

void			map::first_set_map_file(int argc, char *file_path)
{
	string		buffer;
	ifstream	map_file;
	char		*temp;

	this->cur_f = 1;
	this->pre_f = 0;
	if (!(this->check_valid(argc, file_path)))
		exit(0);
	temp = strdup(file_path);
	strcat(temp, "A");
	map_file.open(temp);
	while (map_file.peek() != EOF)
	{
		getline(map_file, buffer);
		this->set_map_line(buffer);
	}
	free(temp);
}

int				main(int argc, char *argv[])
{
	map			map;
	int			x;
	int			y;
	int			idx;

	int flag = 0;

	MyPlayer my_player;
	OtherPlayer other_player;
	my_player.SetPokemon();
	my_player.SetPokemon();
	other_player.SetPokemon();
	other_player.SetPokemon();
	x = 99;
	y = 6;
	map.first_set_map_file(argc, argv[1]);
	system("printf '\e[8;100;200t'");
	system("clear");
	while (1)
	{
		map.draw_player(x, y);
		map.draw_map();
		map.handle_key(map.noah_getch(), &x, &y, my_player, other_player);
		map.change_map(argv[1], map.find_door(&x, &y, my_player), &x, &y);
		system("clear");
	}
	return (0);
}
