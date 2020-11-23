#include <iostream>
#include <stdlib.h>

#include "Battle.h"


using namespace std;


int main()
{
	//system(" mode  con lines=65   cols=200 ");

	Player my_player;
	Player other_player;
	my_player.charizard();
	my_player.charizard();
	other_player.gyarados();
		
	//Battle(&my_player, &other_player).startBattle();

	//std::cout << my_player.pokemons[0]->Attack << std::endl;
	//std::cout << my_player.pokemons[0] << std::endl;

	Battle(&my_player, &other_player);
	//battle.pullPokemon();


    
    
	return 0;
}