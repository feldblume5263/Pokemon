#ifndef MAP_H
#define MAP_H

# include <iostream>
# include <unistd.h>
# include <stdio.h>
# include <vector>
#include <termios.h>
#include <unistd.h>

# define M_KEY_UP		119
# define M_KEY_LEFT		97
# define M_KEY_RIGHT	100
# define M_KEY_DOWN		115
# define M_KEY_SPACE	32


class			map
{
private:

public:
	map();
	~map();

	int pjh_getch();
	void handle_key(int key);

};

map::map()
{
}

map::~map()
{
}

#endif
