#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <unistd.h>
# include <stdio.h>
# include <vector>
# include <termios.h>
# include <unistd.h>
# include <fstream>
# include <string>

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
	vector<string> pokemon_map;

public:
	map();
	~map();

	int check_valid(int argc);
	int noah_getch();
	void handle_key(int key, int *x, int *y);
	void set_map_line(string string);
	void set_map_file(int argc, char *file_path);
	vector<string> get_map_file();
	void draw_player(int x, int y);
	void draw_map();

};

map::map()
{
}

map::~map()
{
}

#endif
