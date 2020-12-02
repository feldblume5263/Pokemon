#include <iostream>
#include <stdlib.h>

#include "../include/Battle.h"


int main()
{
	system(" mode  con lines=65   cols=200 ");

	// width -> 172 height -> 40
	//for (int j = 0; j < 20; ++j)
	//{
	//	for (int k = 0; k < j * 10; ++k)
	//		std::cout << " "; 
	//	
	//	for (int i = 0; i < 10; ++i)
	//		std::cout << i;
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < 60; ++i)
	//	std::cout << i << std::endl;

	//std::string str =
	//	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
	//	"MMMMMMMMMMMMMMMMWWNNNNWWMMMMMMMMMMMMMMMM"
	//	"MMMMMMMMMMMWNWWN0OOOOOO0NWNNWMMMMMMMMMMM"
	//	"MMMNXXNWMMMN0KNKkkkkkkkkKNK0NMMMWNXXNMMM"
	//	"MMKo;:cldOXN0KNKkkkkkkkkKNK0NXOdlc:;oKMM"
	//	"MNd,;lolc;cxO0X0kkkkkkkk0X0Oxc;clol;,dNM"
	//	"MKl,ckkkkxxOO0K0kkkkkkkk0K0OOxxkkkkc'lKM"
	//	"MXo,:dkOKXXXKKX0kkkkkkkk0XXKXXXKOkd:,oXM"
	//	"MWO:,ckKXXXXXXXKOkkkkkkOKXXXXXXXKkc,c0WM"
	//	"MMWKddKXXX0OO0XXXKKKKKKXXXKOO0XXXKddKWMM"
	//	"NXNNXXXXXkxo;:kXXXXXXXXXXOxo::kXXXXNNNXN"
	//	"NXKK0000Kkl;,:kXXXXXXXXXXkl;,ckK000KKKXN"
	//	"MMMWNXKKKX0kk0XXNNNNNNNNXX0kk0XKKKXNWMMM"
	//	"WNNXK000KXKkxO00KKKKKKKK00OxkKXK000KXNNW"
	//	"NKKXXXXXXXX0kdodxxxxxxxxdodx0XXXXXXXXKKN"
	//	"MMMMMMWWNNXXX0O0XXXXXXXX0O0XXXXNWMMMMMMM"
	//	"MMMMMMMMMWWNNXXXXXXXXXXXXXXNNWWMMMMMMMMM"
	//	"MMMMMMMMMMMMWWWWNNNNNNNNWWWWMMMMMMMMMMMM"
	//	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
	//	"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";

	//for (int i = 0; i < 20; ++i)
	//{
	//	for (int j = 0; j < 40; ++j)
	//	{
	//		char c = str[j + i * 40];
	//		if (c == 'M')
	//			std::cout << ' ';
	//		else if (c == ' ')
	//			std::cout <<' /b';
	//		else
	//			std::cout << c;
	//	}
	//	std::cout << std::endl;
	//}



	MyPlayer my_player;
	OtherPlayer other_player;
	//my_player.setItems();
	my_player.SetPokemon();
	my_player.SetPokemon();
	other_player.SetPokemon();
	other_player.SetPokemon();

	
	Battle(&my_player, &other_player);



    
	return 0;
}