#include "../include/map.h"
#include <iostream>
#include <filesystem>
using namespace std;


void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool getArrowkey(int& x1, int& y1)
{
	int c = 0;
	switch ((c = getch()))
	{
	case UP:
		y1 -= 1;
		break;
	case DOWN:
		y1 += 1;
		break;
	case ENTER:
		return true;
	case SPACEBAR:
		return true;
	default:
		break;
	}
	return false;
}

bool getEnterSpacebar()
{
	int c = 0;
	switch ((c = getch()))
	{
	case ENTER:
		return true;
	case SPACEBAR:
		return true;
	default:
		break;
	}
	return false;
}

void printPokemon() {
	cout << "  --------------------------------" << endl;
	cout << "  Pokemon List" << endl;
	cout << "  --------------------------------" << endl;
	cout << "  1.piplup		(팽도리)" << endl;
	cout << "  2.bulbasaur		(이상해씨)" << endl;
	cout << "  3.marill		(마릴)" << endl;
	cout << "  4.totodile		(리아코)" << endl;
	cout << "  5.squirtle		(꼬부기)" << endl;
	cout << "  6.charmander		(파이리)" << endl;
	cout << "  7.haunter		(고우스트)" << endl;
	cout << "  8.charizard		(리자몽)" << endl;
	cout << "  9.meowth		(나옹)" << endl;
	cout << "  10.psyduck		(고라파덕)" << endl;
	cout << "  11.dragonite		(망나뇽)" << endl;
	cout << "  12.pikachu		(피카츄)" << endl;
	cout << "  13.chikorita		(치코리타)" << endl;
	cout << "  --------------------------------" << endl;
}

//bool validPokemon(string poke_name) {
//
//	if (poke_name == "piplup") return true;
//	if (poke_name == "bulbasaur") return true;
//	if (poke_name == "marill") return true;
//	if (poke_name == "totodile") return true;
//	if (poke_name == "squirtle") return true;
//	if (poke_name == "charmander") return true;
//	if (poke_name == "haunter") return true;
//	if (poke_name == "charizard") return true;
//	if (poke_name == "meowth") return true;
//	if (poke_name == "psyduck") return true;
//	if (poke_name == "dragonite") return true;
//	if (poke_name == "pikachu") return true;
//	if (poke_name == "chikorita") return true;
//	cout << "Invalide Pokemon Name" << endl;
//	return false;
//}

void getRandomPokemon(vector<string>& pokemons, int numPokemon)
{
	const int numAllPokemon = 13;
	string list[numAllPokemon] = { "piplup","bulbasaur","marill","totodile","squirtle","charmander",
		"haunter","charizard","meowth","psyduck","dragonite","pikachu","chikorita"};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, numAllPokemon-1);
	int idx;
	for (int i = 0; i < numPokemon; ++i) {
		idx = dis(gen);
		pokemons.push_back(list[idx]);
	}
}

void selectPokemon(int x, int y, vector<string>& pokemons, int numPokemon) {
	const int t_y = y;

	printPokemon();
	cout << "You can choose 3 pokemons" << endl;
	cout << "After select pokemon, press the enter or space" << endl;

	for (int i = 0; i < numPokemon; ++i) {

		gotoxy(x, y + 1);
		std::cout << "O\b";
		while (getArrowkey(x, y) == false)
		{
			std::cout << " \b" << std::endl;

			if (y < t_y)
			{
				y += 1;
			}
			else if (y > t_y + 12)
			{
				y -= 1;
			}
			gotoxy(x, y + 1);
			std::cout << "O\b";
		}

		switch (y - t_y)
		{
		case 0:
			pokemons.push_back("piplup");
			break;
		case 1:
			pokemons.push_back("bulbasaur");
			break;
		case 2:
			pokemons.push_back("marill");
			break;
		case 3:
			pokemons.push_back("totodile");
			break;
		case 4:
			pokemons.push_back("squirtle");
			break;
		case 5:
			pokemons.push_back("charmander");
			break;
		case 6:
			pokemons.push_back("haunter");
			break;
		case 7:
			pokemons.push_back("charizard");
			break;
		case 8:
			pokemons.push_back("meowth");
			break;
		case 9:
			pokemons.push_back("psyduck");
			break;
		case 10:
			pokemons.push_back("dragonite");
			break;
		case 11:
			pokemons.push_back("pikachu");
			break;
		case 12:
			pokemons.push_back("chikorita");
			break;
		}

		gotoxy(x, y + 15 + i);
		std::cout << "Add the " << pokemons[i] << " in my pokemons" << std::endl;
	}

}

void drawPokemonstBox()
{
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "|                                                            |" << std::endl;
	std::cout << "|                                                            |" << std::endl;
	std::cout << "|                         POKEMONSTER                        |" << std::endl;
	std::cout << "|                                                            |" << std::endl;
	std::cout << "|                                                            |" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
}

void selectPokemons(MyPlayer& my_player, OtherPlayer& other_player)
{
	drawPokemonstBox();

	std::cout << "\n press Enter or Space bar to start the game" << std::endl;
	std::cout << " GAME START" << std::endl;
	while (!getEnterSpacebar());

	system("cls");
	drawPokemonstBox();
	std::cout << "\n\n" << std::endl;

	int x = 0; int y = 13;
	int numPokemon = 3;
	vector<string> myPokemons;
	vector<string> otherPokemons;
	selectPokemon(x, y, myPokemons, numPokemon);
	getRandomPokemon(otherPokemons, numPokemon);

	std::cout << "\npress Enter or Space bar to collet pokemon information for pokeAPI" << std::endl;
	while (!getEnterSpacebar());

	system("cls");
	drawPokemonstBox();

	gotoxy(x, y - 5);
	std::cout << "We are going to collet pokemon information from pokeAPI." << std::endl;
	gotoxy(x, y - 4);
	std::cout << "Take some seconds.\n" << std::endl;


	for (int i = 0; i < numPokemon; ++i)
	{
		std::cout << ". . ." << std::endl;
		my_player.SetPokemon(myPokemons[i]);
		my_player.GetPokemon(i)->setStat();
		my_player.GetPokemon(i)->setRemainHp(my_player.GetPokemon(i)->getHealthPoint());
		//gotoxy(x, y + i * 2);
		std::cout << "My" << " pokemon " << i + 1 << " is stored.\n" << std::endl;
	}

	for (int i = 0; i < numPokemon; ++i)
	{
		std::cout << ". . ." << std::endl;
		other_player.SetPokemon(otherPokemons[i]);
		other_player.GetPokemon(i)->setStat();
		other_player.GetPokemon(i)->setRemainHp(other_player.GetPokemon(i)->getHealthPoint());
		std::cout << "Other" << " pokemon " << i + 1 << " is stored.\n" << std::endl;
	}

	std::cout << "\nPress Enter or SpaceBar to Play" << std::endl;
	while (!getEnterSpacebar());
}


int				main(int argc, char* argv[])
{
	//system("printf '\e[8;100;200t'");
	system(" mode  con lines=65   cols=200 ");

	//char path[] = "C:\Users\youju\\source\repos\push\gold_version\";
	std::string temp_path = "..\\gold_version\\";
	std::cout << "Enter your map folder absolute path or relative path" << std::endl;
	std::cout << " ex)\\repos\\push\\gold_version\\" << std::endl;
	std::cout << " ex)..\\gold_version\\" << std::endl;
	std::cout << "GAME VERSION : " << std::flush;
	std::getline(std::cin, temp_path);

	char path[100] = "0";
	int numSlash = 0;
	for (int ix = 0; ix < temp_path.size(); ++ix)
	{
		if (temp_path[ix] == '\\')
		{
			path[ix + numSlash] = '\\';
			path[ix + numSlash +1] = '\\';
			numSlash += 1;
		}
		path[ix + numSlash] = temp_path[ix];
	}

	// push the pokemon in player
	MyPlayer my_player;
	OtherPlayer other_player;
	selectPokemons(my_player, other_player);

	Map			map;
	int			idx;
	map.first_set_map_file(argc, path);
	my_player.SetPos(99, 6);
	system("cls");

	// map display
	while (1)
	{
		map.draw_player(my_player.GetPos().x, my_player.GetPos().y);
		map.draw_map();
		map.handle_key(getch(), my_player.GetPos().x, my_player.GetPos().y, &my_player, &other_player);
		map.change_map(&my_player, path, map.find_door(my_player.GetPos().x, my_player.GetPos().y, &my_player), my_player.GetPos().x, my_player.GetPos().y);
		system("cls");
	}

	return (0);
}
