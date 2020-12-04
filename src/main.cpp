#include "../include/map.h"




void printPokemon() {
	cout << "--------------------------------" << endl;
	cout << "Pokemon List" << endl;
	cout << "--------------------------------" << endl;
	cout << "1.piplup		(팽도리)" << endl;
	cout << "2.bulbasaur		(이상해씨)" << endl;
	cout << "3.marill		(마릴)" << endl;
	cout << "4.totodile		(리아코)" << endl;
	cout << "5.squirtle		(꼬부기)" << endl;
	cout << "6.charmander		(파이리)" << endl;
	cout << "7.haunter		(고우스트)" << endl;
	cout << "8.charizard		(리자몽)" << endl;
	cout << "9.meowth		(나옹)" << endl;
	cout << "10.psyduck		(고라파덕)" << endl;
	cout << "11.dragonite		(망나뇽)" << endl;
	cout << "12.pikachu		(피카츄)" << endl;
	cout << "13.chikorita		(치코리타)" << endl;
	cout << "--------------------------------" << endl;
}
bool validPokemon(string poke_name) {


	if (poke_name == "piplup") return true;
	if (poke_name == "bulbasaur") return true;
	if (poke_name == "marill") return true;
	if (poke_name == "totodile") return true;
	if (poke_name == "squirtle") return true;
	if (poke_name == "charmander") return true;
	if (poke_name == "haunter") return true;
	if (poke_name == "charizard") return true;
	if (poke_name == "meowth") return true;
	if (poke_name == "psyduck") return true;
	if (poke_name == "dragonite") return true;
	if (poke_name == "pikachu") return true;
	if (poke_name == "chikorita") return true;
	cout << "Invalide Pokemon Name" << endl;
	return false;

}

vector<string> getRandomPokemon() {
	string list[14] = { "venusaur","charizard","blastoise","butterfree","pidgeot","pikachu",
		"alakazam","scyther","gyarados","lapras","vaporeon","jolteon","flareon","snorlax" };
	vector<string> ret;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 13);
	bool check[14] = { false, };
	int idx;
	for (int i = 0; i < 1;) {
		idx = dis(gen);
		if (!check[idx]) {
			ret.push_back(list[idx]);
			check[idx] = true;
			i++;
		}

	}
	return ret;
}

vector<string> selectPokemon() {

	vector<string> ret;
	printPokemon();
	cout << "You can choose 3 pokemons" << endl;
	for (int i = 0; i < 1;) {
		string temp;
		cout << "Enter name of pokemon in English:";
		cin >> temp;
		if (validPokemon(temp)) {
			ret.push_back(temp);
			cout << "Pokemon added" << endl;
			i++;
		}

	}
	return ret;


}





int				main(int argc, char* argv[])
{
	//system("printf '\e[8;100;200t'");
	system(" mode  con lines=65   cols=200 ");

	vector<string> myPokemons = selectPokemon();
	//vector<string> otherPokemons = getRandomPokemon();
	vector<string> otherPokemons = selectPokemon();

	MyPlayer my_player;
	OtherPlayer other_player;

	for (int i = 0; i < 1; ++i)
	{
		other_player.SetPokemon(otherPokemons[i]);
		my_player.SetPokemon(myPokemons[i]);

		my_player.GetPokemon(i)->setStat();
		other_player.GetPokemon(i)->setStat();

		my_player.GetPokemon(i)->setRemainHp(my_player.GetPokemon(i)->getHealthPoint());
		other_player.GetPokemon(i)->setRemainHp(other_player.GetPokemon(i)->getHealthPoint());
	}

	//system("pause");

	//OtherPlayer other_player;
	//MyPlayer my_player;
	//my_player.SetPokemon();
	//my_player.SetPokemon();
	//other_player.SetPokemon();
	//other_player.SetPokemon();
	Battle battle(&my_player, &other_player);

	//std::string str1 = "abc def g";
	//std::cout << str1 << std::endl;

	//while (str1.find(' '))
	//{
	//	str1.erase(str1.find(' '), 1);
	//}
	//std::cout << str1 << std::endl;

	//Map			map;
	//int			idx;

	//char path[] = "..\\gold_version\\";
	//char path[] = "C:\\Users\\youju\\source\\repos\\push\\gold_version\\";


	//map.first_set_map_file(argc, path);
	//my_player.SetPos(99, 6);
	//system("cls");
	//while (1)
	//{
	//	map.draw_player(my_player.GetPos().x, my_player.GetPos().y);
	//	map.draw_map();
	//	map.handle_key(getch(), my_player.GetPos().x, my_player.GetPos().y, &my_player, &other_player);
	//	map.change_map(&my_player, path, map.find_door(my_player.GetPos().x, my_player.GetPos().y, &my_player), my_player.GetPos().x, my_player.GetPos().y);
	//	system("cls");
	//}
	return (0);

}
