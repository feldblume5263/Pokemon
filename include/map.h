#ifndef MAP_H
#define MAP_H

# include <iostream>
//# include <unistd.h>
# include <stdio.h>
# include <vector>
//# include <termios.h>
# include <fstream>
# include <string>
# include <string.h>
# include <cstdlib>
# include "Battle.h"

# define M_KEY_UP		119
# define M_KEY_LEFT		97
# define M_KEY_RIGHT	100
# define M_KEY_DOWN		115
# define M_KEY_SPACE	32
# define M_KEY_ESC		27
# define M_ENTER		13

# define ERROR			0
# define TRUE			1

using namespace std;

class				Map
{
private:
	vector<string>	pokemon_map;
	int				cur_f;
	int				pre_f;

public:
	//map()
	//{
	//	cur_f = 1;
	//	pre_f = 0;
	//}
	//~map()
	//{
	//}

	int check_valid(int argc, char *file_path);
	//int noah_getch();
	void handle_key(int key, int x, int y, MyPlayer *p, OtherPlayer *o);
	void set_map_line(string string);
	void first_set_map_file(int argc, char *file_path);
	void change_map(MyPlayer *p, char *path, int open_flag, int x, int y);
	void delete_pre_map();
	void relocate_p(MyPlayer *p, int x, int y);
	vector<string> get_map_file();
	void draw_player(int x, int y);
	void draw_map();
	int find_door(int x, int y, MyPlayer *p);
	void get_pos();
	void set_pos(int x, int y);
};

#endif
