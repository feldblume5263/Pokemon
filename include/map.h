#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <unistd.h>
# include <stdio.h>
# include <vector>
# include <termios.h>
# include <fstream>
# include <string>
# include <string.h>
# include <cstdlib>

# define M_KEY_UP		119
# define M_KEY_LEFT		97
# define M_KEY_RIGHT	100
# define M_KEY_DOWN		115
# define M_KEY_SPACE	32
# define M_KEY_ESC		27

# define ERROR			0
# define TRUE			1

using namespace std;

class			map
{
private:
	vector<string>	pokemon_map;
	int				cur_f;
	int				pre_f;

public:
	map();
	~map();

	int check_valid(int argc, char *file_path);
	int noah_getch();
	void handle_key(int key, int *x, int *y);
	void set_map_line(string string);
	void first_set_map_file(int argc, char *file_path);
	void set_map_file(char *path, int open_flag);
	void delete_pre_map();
	vector<string> get_map_file();
	void draw_player(int x, int y);
	void draw_map();
	int find_door(int *x, int *y);

};

map::map()
{
	cur_f = 1;
	pre_f = 0;
}

map::~map()
{
}

#endif
