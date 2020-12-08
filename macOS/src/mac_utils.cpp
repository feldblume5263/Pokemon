#include <termios.h>
#include <iostream>
#include <unistd.h>
#include "mac_utils.h"

int			noah_getch()
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
