#include <iostream>
#include <stdlib.h>

#include "Battle.h"


using namespace std;


int main()
{
	//system(" mode  con lines=65   cols=200 ");



	MyPlayer my_player;
	OtherPlayer other_player;
	my_player.setItems();

	my_player.gyarados();
	my_player.charizard();
	other_player.charizard();
	other_player.gyarados();


	Battle(&my_player, &other_player);



    
	return 0;
}