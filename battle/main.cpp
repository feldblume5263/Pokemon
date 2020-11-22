#include <iostream>
#include "Battle.h"


using namespace std;


int main()
{
	Player my_player;
	Player other_player;
	my_player.charizard();
	other_player.gyarados();

	Battle(&my_player, &other_player).startBattle();

    
    
	return 0;
}