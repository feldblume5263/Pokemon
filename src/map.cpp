#include "map.h"

void		map::delete_pre_map()
{
	int		idx;
	int		size;

	idx = 0;
	size = this->pokemon_map.size();
	while(idx < size)
	{
		this->pokemon_map[idx].erase();
		idx++;
	}
}

int			map::find_door(int *x, int *y)
{
	if (this->pokemon_map[*y - 1][*x] <= '9' && this->pokemon_map[*y - 1][*x] >= '1')
		return (this->pokemon_map[*y - 1][*x] - 48);
	else if (this->pokemon_map[*y + 1][*x] <= '9' && this->pokemon_map[*y + 1][*x] >= '1')
		return (this->pokemon_map[*y + 1][*x] - 48);
	else if (this->pokemon_map[*y][*x - 1] <= '9' && this->pokemon_map[*y][*x - 1] >= '1')
		return (this->pokemon_map[*y][*x - 1] - 48);
	else if (this->pokemon_map[*y][*x + 1] <= '9' && this->pokemon_map[*y][*x + 1] >= '1')
		return (this->pokemon_map[*y][*x + 1] - 48);
	return (0);
}

void		map::handle_key(int key, int *x, int *y)
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
		std::cout << "space" << std::endl;
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
		cout << "please compile with pokemon file" << endl;
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
	strcat(temp, "1");
	map_file.open(temp);
	while (map_file.peek() != EOF)
	{
		getline(map_file, buffer);
		this->set_map_line(buffer);
	}
	free(temp);
}

void			map::set_map_file(char *path, int open_flag)
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
	num[0] = open_flag + '0';
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

}

int				main(int argc, char *argv[])
{
	map			map;
	int			x;
	int			y;
	int			idx;

	int flag = 0;

	x = 100;
	y = 5;
	map.first_set_map_file(argc, argv[1]);
	system("printf '\e[8;100;200t'");
	system("clear");
	while (1)
	{
		map.draw_player(x, y);
		map.draw_map();
		map.handle_key(map.noah_getch(), &x, &y);
		map.set_map_file(argv[1], map.find_door(&x, &y));
		system("clear");
	}
	return (0);
}
