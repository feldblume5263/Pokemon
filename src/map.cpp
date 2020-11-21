#include "../include/map.h"

void		map::handle_key(int key)
{
	if (key == M_KEY_UP)
	{
		std::cout << "up" << std::endl;
	}
	else if (key == M_KEY_DOWN)
	{
		std::cout << "down" << std::endl;
	}
	else if (key == M_KEY_RIGHT)
	{
		std::cout << "right" << std::endl;
	}
	else if (key == M_KEY_LEFT)
	{
		std::cout << "left" << std::endl;
	}
	else if (key == M_KEY_SPACE)
	{
		std::cout << "space" << std::endl;
	}
	else if (key == M_KEY_ESC)
	{
		std::cout << "ESC" << std::endl;
		exit(0);
	}
	else
		return ;
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

int				main(void)
{
	map			map;
	int			pressed;

	while (1)
	{
		pressed = map.noah_getch();
		map.handle_key(pressed);
	}
}
