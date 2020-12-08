#include"../include/pokemon.h"
#include<random>
#include<cmath>
#include<iostream>

const double nature_stat_rate[25][5] = {
	//				a		b		c		d		s
					{1.1,	0.9,	1.0,	1.0,	1.0},
					{1.1,	1.0,	0.9,	1.0,	1.0},
					{1.1,	1.0,	1.0,	0.9,	1.0},
					{1.1,	1.0,	1.0,	1.0,	0.9},
					{0.9,	1.1,	1.0,	1.0,	1.0},
					{1.0,	1.1,	0.9,	1.0,	1.0},
					{1.0,	1.1,	1.0,	0.9,	1.0},
					{1.0,	1.1,	1.0,	1.0,	0.9},
					{0.9,	1.0,	1.1,	1.0,	1.0},
					{1.0,	0.9,	1.1,	1.0,	1.0},
					{1.0,	1.0,	1.1,	0.9,	1.0},
					{1.0,	1.0,	1.1,	1.0,	0.9},
					{0.9,	1.0,	1.0,	1.1,	1.0},
					{1.0,	0.9,	1.0,	1.1,	1.0},
					{1.0,	1.0,	0.9,	1.1,	1.0},
					{1.0,	1.0,	1.0,	1.1,	0.9},
					{0.9,	1.0,	1.0,	1.0,	1.1},
					{1.0,	0.9,	1.0,	1.0,	1.1},
					{1.0,	1.0,	0.9,	1.0,	1.1},
					{1.0,	1.0,	1.0,	0.9,	1.1},
					{1.0,	1.0,	1.0,	1.0,	1.0},
					{1.0,	1.0,	1.0,	1.0,	1.0},
					{1.0,	1.0,	1.0,	1.0,	1.0},
					{1.0,	1.0,	1.0,	1.0,	1.0},
					{1.0,	1.0,	1.0,	1.0,	1.0}
};



Pokemon::Pokemon() {

	//from database//////////
	this->name = "Pikachu";
	this->base_health_point = 35;
	this->base_attack = 55;
	this->base_defense = 40;
	this->base_special_attack = 50;
	this->base_special_defense = 50;
	this->base_speed = 90;
	this->type1 = Electric;
	this->type2 = None;

	emoji = "MMMMMMMMN0kdlc:;;,,,,,,,;;:loxOXWMMMMMMMMMMMMN0dc;;::ccccccccccccccc:;;:lkXWMMMMMMMNOo:::cccccccccccccccccccccc:;,:xXMMMMWKd::ccccccccccccccccccccccccccc:;:d0WMW0lccc::::::::ccccccccccccccccccc:d0OxON0lcc:cdk0KK0kdc::cccccccc:llc:::;c0NX0dOdcccxXWMMMMMMWXkc:ccc::::oOKOdlclkNNOkkdc:cOWMMMMMMMMMMMXkdxkkddx0KKKK00O0NOocdd;:xWMMMMMMNOooxXMWKxdkKKKKKKKKKK0KKl,.cd,:OMMMMMMMOdkl.cKMMX0xkKK0OOOkxxxKK; .cd,:OMMMMMMWx;:'..lNMMMNkkkkOKKKkdlkXl.'odc,dWMMMMMMO,.  .:0MMMMNxoOXXXXKOod0kldxkO;;kWMMMMMNd'...:KMMMMM0ox00KK0kolOKKOkKW0c;xNMMMMMNOl:lOWMMMMMNOooooollok00kkKMMMXxclkXMMMMMWNWMMMMMMMMMNK0OkkO00kk0NMMMMMMNOoodk0XNWMMMMMMMMMMMMWNX0kdlcxXMMMMMMMMMWKxc;;cloddxkkkkkkxxdolc:,''':kWMMMMW0kkxdlcll::::;;;;,,,,,,'.',,,,,,':0MMMxd:,:cldOXKd:;:ccccccc:;,,cc;'',,,',xNMMc:,,:d0XNXXKkl:;;;;;,;;;cx0KOdc:;;;loOWMKo,;kXNNXX0xOKOxlcloooox0KKKKKOkOxclddKMMKokNNNXX0ddKKK0kKWMMMNOOKKKK0kOKkccxdOWWOkXNXXX0do0KKKOONMMMMW0kKKKKKkxkd:cxoxNXxOXXKKOolkKKKK0O0XNNXKO0KKKKKOddl;:dlxW0xOKK0kllkKKKKKKK000000KKKKK0kxxdcoxodKM0xOKkolcokO00KKKKKKKKKK0OkxxxoldXWNNMMNxoookXKl:cloxkkkkkkkkkkxxxdolcclONMMMMMMX00NMW0dool:cddddooooodolc:cldkdodKMMMMMMMMMM0ddk0xcl0NNXXKKKXXXK00OOOOOkOXMMMMMMMMMMXxlodlcxNMMMMMMMMMMMMMMMMMMMMMMMMM";


	/////////////////////////
	setIndiStat();
	setEffStat();
	setNature();
	setStat();
	for (int i = 0; i < 4; i++) {
		this->moves[i] = new Skill();
	}
	num_of_skill = 0;
}
Pokemon::Pokemon(string name) {
	this->name = name;
	moves[0] = nullptr;
	moves[1] = nullptr;
	moves[2] = nullptr;
	moves[3] = nullptr;

	setIndiStat();
	setEffStat();
	setNature();

	setEmoji(name);

	num_lines_emoji = emoji.length() / 40;
}
Pokemon::~Pokemon() {
	delete moves[0];
	delete moves[1];
	delete moves[2];
	delete moves[3];
}

void Pokemon::setIndiStat() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 31);
	this->indi_health_point = dis(gen);
	this->indi_attack = dis(gen);
	this->indi_defense = dis(gen);
	this->indi_special_attack = dis(gen);
	this->indi_special_defense = dis(gen);
	this->indi_speed = dis(gen);
}
void Pokemon::setEffStat() {
	this->eff_health_point = 0;
	this->eff_attack = 0;
	this->eff_defense = 0;
	this->eff_special_attack = 0;
	this->eff_special_defense = 0;
	this->eff_speed = 0;


	int i = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);
	for (i = 0; i < 510; i++) {
		int select = dis(gen);
		switch (select) {
		case 1:
			if (this->eff_health_point < 253) {
				this->eff_health_point++;

			}
			continue;

		case 2:
			if (this->eff_attack < 253) {
				this->eff_attack++;

			}
			continue;
		case 3:
			if (this->eff_defense < 253) {
				this->eff_defense++;


			}
			continue;
		case 4:
			if (this->eff_special_attack < 253) {
				this->eff_special_attack++;

			}
			continue;
		case 5:
			if (this->eff_special_defense < 253) {
				this->eff_special_defense++;

			}
			continue;


		case 6:
			if (this->eff_speed < 253) {
				this->eff_speed++;

			}
			continue;

		}
	}
}


void Pokemon::setNature() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 24);
	int num = dis(gen);
	this->nature = static_cast<Nature>(num);



}

Nature Pokemon::getNature() {
	return this->nature;
}
void Pokemon::setStat() {

	health_point = ceil(((double)base_health_point * 2 + (double)indi_health_point + (double)eff_health_point / 4) / 2 + 10 + 50);
	attack = (int)ceil((((double)base_attack * 2 + (double)indi_attack + (double)eff_attack / 4) / 2 + 5) * nature_stat_rate[getNature()][0]);
	defense = (int)ceil((((double)base_defense * 2 + (double)indi_defense + (double)eff_defense / 4) / 2 + 5) * nature_stat_rate[getNature()][1]);
	special_attack = (int)ceil((((double)base_special_attack * 2 + (double)indi_special_attack + (double)eff_special_attack / 4) / 2 + 5) * nature_stat_rate[getNature()][2]);
	special_defense = (int)ceil((((double)base_special_defense * 2 + (double)indi_special_defense + (double)eff_special_defense / 4) / 2 + 5) * nature_stat_rate[getNature()][3]);
	speed = (int)ceil((((double)base_speed * 2 + (double)indi_speed + (double)eff_speed / 4) / 2 + 5) * nature_stat_rate[getNature()][4]);
}



string Pokemon::getName() {
	return this->name;

}
int Pokemon::getHealthPoint() {
	return this->health_point;
}
int Pokemon::getAttack() {
	return this->attack;
}
int Pokemon::getDefense() {
	return this->defense;
}
int Pokemon::getSpecialAttack() {
	return this->special_attack;
}
int Pokemon::getSpecialDefense() {
	return this->special_defense;
}
int Pokemon::getSpeed() {
	return this->speed;
}
Type Pokemon::getType1() {
	return this->type1;
}
Type Pokemon::getType2() {
	return this->type2;
}
void Pokemon::setName(string name) {
	this->name = name;
}
void Pokemon::setHealthPoint(int num) {
	this->base_health_point = num;
}
void Pokemon::setAttack(int num) {
	this->base_attack = num;

}
void Pokemon::setDefense(int num) {
	this->base_defense = num;
}
void Pokemon::setSpecialAttack(int num) {
	this->base_special_attack = num;

}
void Pokemon::setSpecialDefense(int num) {
	this->base_special_defense = num;
}
void Pokemon::setSpeed(int num) {
	this->base_speed = num;
}
void Pokemon::setType1(string name) {

	this->type1 = searchType(name);
}
void Pokemon::setType2(string name) {

	this->type2 = searchType(name);
}
void Pokemon::setSkill(int idx, Skill* skill) {
	this->moves[idx] = skill;
	idx++;
}



void Pokemon::showInfo() {
	cout << this->name << endl;
	cout << "hp:" << this->health_point << endl;

	cout << "attack:" << this->attack << endl;

	cout << "defense:" << this->defense << endl;

	cout << "special-attack:" << this->special_attack << endl;

	cout << "special-defense:" << this->special_defense << endl;

	cout << "speed:" << this->speed << endl;

	for (int i = 0; i < 4; i++) {
		this->moves[i]->showInfo();
	}
}
Skill* Pokemon::getSkill(int idx) {
	return this->moves[idx];
}

void Pokemon::setEmoji(string poke_name) {
	if (poke_name == "piplup") emoji = "MMMMMMMMN0kdlc:;;,,,,,,,;;:loxOXWMMMMMMMMMMMMN0dc;;::ccccccccccccccc:;;:lkXWMMMMMMMNOo:::cccccccccccccccccccccc:;,:xXMMMMWKd::ccccccccccccccccccccccccccc:;:d0WMW0lccc::::::::ccccccccccccccccccc:d0OxON0lcc:cdk0KK0kdc::cccccccc:llc:::;c0NX0dOdcccxXWMMMMMMWXkc:ccc::::oOKOdlclkNNOkkdc:cOWMMMMMMMMMMMXkdxkkddx0KKKK00O0NOocdd;:xWMMMMMMNOooxXMWKxdkKKKKKKKKKK0KKl,.cd,:OMMMMMMMOdkl.cKMMX0xkKK0OOOkxxxKK; .cd,:OMMMMMMWx;:'..lNMMMNkkkkOKKKkdlkXl.'odc,dWMMMMMMO,.  .:0MMMMNxoOXXXXKOod0kldxkO;;kWMMMMMNd'...:KMMMMM0ox00KK0kolOKKOkKW0c;xNMMMMMNOl:lOWMMMMMNOooooollok00kkKMMMXxclkXMMMMMWNWMMMMMMMMMNK0OkkO00kk0NMMMMMMNOoodk0XNWMMMMMMMMMMMMWNX0kdlcxXMMMMMMMMMWKxc;;cloddxkkkkkkxxdolc:,''':kWMMMMW0kkxdlcll::::;;;;,,,,,,'.',,,,,,':0MMMxd:,:cldOXKd:;:ccccccc:;,,cc;'',,,',xNMMc:,,:d0XNXXKkl:;;;;;,;;;cx0KOdc:;;;loOWMKo,;kXNNXX0xOKOxlcloooox0KKKKKOkOxclddKMMKokNNNXX0ddKKK0kKWMMMNOOKKKK0kOKkccxdOWWOkXNXXX0do0KKKOONMMMMW0kKKKKKkxkd:cxoxNXxOXXKKOolkKKKK0O0XNNXKO0KKKKKOddl;:dlxW0xOKK0kllkKKKKKKK000000KKKKK0kxxdcoxodKM0xOKkolcokO00KKKKKKKKKK0OkxxxoldXWNNMMNxoookXKl:cloxkkkkkkkkkkxxxdolcclONMMMMMMX00NMW0dool:cddddooooodolc:cldkdodKMMMMMMMMMM0ddk0xcl0NNXXKKKXXXK00OOOOOkOXMMMMMMMMMMXxlodlcxNMMMMMMMMMMMMMMMMMMMMMMMMM";
	if (poke_name == "bulbasaur") emoji = "MMMWXOxdd0NWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNklcllodkOO000KKKKXNWMMMMMMMMMMMMMMMMMMMM0c:cloooooooooodddxkOXWMMMMMMMMMMMMMMMMXd::cloodddoooooooolloxKNNNWNNXXNWMMMMWKo:;:cllooooookOOOkkkkkkO000K0OOO0XWMMW0l:;;coooollccoxOOOOOOOkdllodxkO000KNMMOl:;:coxkxol:::lxOOOOOOOOxoc;,;:dO000KWMc:lodddolc:::cccdkOOO0kxkOOkdlcdkdokkOKW;,;;;;;;,,,:llccokOKNKocxkOOdc:okxxkdd0X;,,,,,''''',;ccclx0NM0clkxkOkddkOOOOxdOKd;,,,,'''',;;;::cokKXOooookOOOOOOOOOxxOON0x:;;,,,,;;:::::clodddddxkkkkOkkOkxxdk0MNkc;:;;;;;:loolc::::::cccllooddddddk0NWM0l:::cc:;;col:cll:;;::cclllloodddx0WMMMWkc::;;:c:;coddxkko:;;;;::ccloddodkKWMMMM0c:c;,,::;;lxO0Oo:;,,,;ldo::col;;lKMMMMMNkc:::::cclloxOOd:;,,;xXWNkccoolcxXMMMMMMNOollllxXWXOddxkxdookNMMMW0ddxkOXMMMMMMMMWXKK00NMMMWKkxkOOOKNMMMMMWNXXXNWMMMMM";
	if (poke_name == "marill") emoji = "MWNXKKXNWMMMMWXOdlccccoxKWMMMMMMMWNXXWMMKkdllllokXWMW0oc::::::::oKMMMMMWKxooodOXollllccccdXWKd:::ccllolccxKXNWWKoc::::cdccccccc::l0W0l::cldddddlccloodxdc::cllccdccc:::::xXMXxc:lddollccccccccccc:coodolXkc;:cldONMMMXd::ccc:ccccccccccccccooookMWOlkKXWMMMMWOl:::cccccc:clcccccclclxOKWMMXolKMMMMMWKoccccccccc:,,;:cccc:;;l0WMMMMM0lOWMMMMNkcccccccccccc:ccccccc::cOWMMMMMk;cdKWNNNxcccccccccccccccccccccccxXNWMMWKO0ololooc::::::cllodxxkkkkkxdl::clodMMMMMMNo;kXOoc:coxO0KXXNWWWWNNNXX0xOKOk0MMMMMMMNNWMMWKxxKXXNXNNNXXXXXXKKKKNWMMMMMMMMMMMMMMMMMXdldOKKKKKKKKKK00O0XWMMMMMMMMMMMMMMMMMMWOc:l0NNXXXXXXXKkl:xNMMMMMMMMMMMMMMMMMMMW0l:xNMMMMMMMMMMKdd0WMMMMMMM";
	if (poke_name == "totodile") emoji = "MMMMMMMMMMMMMMMMMMWXKK0O00KKKXNWMMMMMMMMMMMMMMMMMMMMMMMMMNKOkkOOOO0Oxdk0NWMMMMMMMMMMMMMMMMMMMMMMN0xoookK0OkOOxxk0NWMMMMMMMMMMMMMMMMMMMMWKdoc:l0KkklokOOOO0XNWWWMMMMMMMMMMMMMWWNKxlloooO0Okook000000KKKXNMMMMMMMMMMMNK0Odlc:ccldxkkkkOOOO0000000KMMMMMMMMMMMWXOxl::;::::clodoodddxkOkO00KMMMMMMMWNNXXKOdl:;;::::ccclloddxxxxxOXXWMMMMMMMNKOkkkxoc;;coddxxxxdolclllokKWMMMMMMMMMMMWX0kkxo:;:oxkO00KXXkddooox0WMMMMMMMMMMMMNXKOxdc:::lxkO000KKxlodxxdxKWMMMMMMMMMMMW0kxdl:::::oxk000OOOxk0XXOdxKNMMMNXNWMMMMNkolccccc:cldO00OO0000000dlxXMMW0O0KNWWX0xllcccoddoloxkOOO0000000OkKWMMXkxxxkOkdlllc:cldkOOOOOO0000O0000OO0KNMMOolollllllcc:;:ldkOO00000KKOOOOOkxkOKWMMX0kdlccccc::;;;coxkOOO0000OkdoollloxKNWWMMWWX0kxolc:;;,;:lodxxkkOkdc::;;:cokOOO0MMMMMMMMWNXKOkko:;:cccloxOOkkxxdddxxkO0XMMMMMMMMMMMMMMXxlllooodxkO0NWMMMWWNXXWMMMMMMMMMMMMMMMMKxddooooodxxOXWMMMMMMMMMMM";
	if (poke_name == "squirtle") emoji = "MMMMMMMMMWNX00OOOO0KXNWMMMMMMMMMMMMMMMMMMMMMMMMWNK000000OOOOO0KNWMMMMMMMMMMMMMMMMMMMMMMKkO00O00OkkddOO0O0NMMMMMMMMMMMMMMMMMMMMNdlO00000x:,,lOOOxd0WMMMMMMMMMMMMMMMMMMWXxxO00000d;';xOOkdoOWMMMMMMMMMMMMMMMMMMWXOOOOOOOOOkxxOOOxod0WMMMMMMMMMMMMMMMMMMMWX0kOOOOOOOOkxxdodkXMMMMMMMMMMMMMMMMMMMMWNKkxdxxxxxdoolookkx0WMMMMMMMMMMMMMMMWNK0OkO0kxxxxxdddddxxo:lONMMMMMMMMMMMXXK0kxddkKKKK00OOkOO00Oxoc:lOWMMMMMMMMMMOddoooox0XKKKKKKOOOOOOxdooccdXMMMMMMMMMMOkkkkkkOXXXXKKXKOkxxxxookkl:o0MMMMMMMMMMMWWWWWNKKXXXKXX0kxdodddkKk::l0WMMMMWWMMMMMMMMMNKKKKKKKKKK0kkkkk0Xx:;oKWWXKKKKKXWMMMMMWK0KXXXKXXXK0kxxxxkOkc:xXX000000000MMMMWK0OkO0K0000OkkkkkOOkdlo0K000OOOOOOxMMMMN0OxoodxxkkkkkO00000Odox00OOkxkkkxddMMMW0xdooookKK00OOOO0000kdodxxddooooodkKMMWKxooodxONMMMWWWKkkkkkdook00OOkkkO0XWMMMMWNK0XNNWMMMMMMMNkooooood0WMMMMWWMMMMMMMMMMMMMMMMMMMMMMMWKkkkxdkOXMMMMMMMMMMMM";
	if (poke_name == "charmander") emoji = "MMMMMMNKOkxddxxOKNMMMMMMMMMMMMMMMMMMMMMMMMMMMN0xdddddddddOXWMMMMMMMMMMMMMMMMMMMMMMMMNdlddddddxkl:oONMMMMMMMMMMMMMMMMMMMMMMMNOllddddddol'.cxKWMMMMMMMMMMMMMMMMMMMMWXOxdddddddo:..:oxKWWMMMMMMMMMMMMMMMMMMMW0xddddddddddooddxKWWMMMMMMMMMMMMMWNNMMWWXkdddddddddddoddxKWWMMMMMMMMMMMWX0dkNWKO00dloooooollllodx0NNWNXK0KWMMMMXdc:ldOkddxdddddxdddddddddxkkkxxdoxXWMMMNOdoc:dX0kddddxOOOO0KKOxdddddddddkKNMMMMMNXOoccMWX0xod0XXKXXXXX0kdddooxOKNMMMMMMWNXK0xoMMMWX0OKXXXXXXXXX0kddddONMMMMMMMMMWNXK0KMMMMMWNXXXXXXXXXXX0xdddkKWMMMMMMMMMWKO0WMMMMMMNXXXXXXXXXXXKkddddONMMMMMMMMMNOkKMMMMMMMWXXXXXXXXXXXXOxdddxKWMMMMMMWNOxkXMMMMMMWX0KXXXXXXXXXKkdddddkKNNNNXK0kdxKWMMMMMN0xxk0KXXXXXXX0xdddddddxkkxxddxkKWMMMMMWKxdddddxO0KKKOxddddddddddddxxk0NWMMMMMMWXkdddolld0XX0xdddddddxOOOO0KXNWMMMMMMWNKOxooolllkNMMNOddooookXNWWWWWMMMMMMMMWNX0Oxxxdddx0NMMNOxxxxxx0NMMMMMMMMMMMMMMMMWNNXXXXNNWMMMMWXK0000KXWMMMMMMMMMMMMMM";
	if (poke_name == "haunter") emoji = "MMMKddOXNWMMMMMMMMMMMMMMMMMW0kKMMMMMMMMMMMMWOccoxO0XNWMMMMMMMMMMMN0xoo0WMMMMMMMMMMMMNk:;:cldxk0KNNNNWWWXOoccloONMMMMMMMMWWMMMNx:;;:clooddddddxxoccclodkXMMMMMMMMOxxxkkx:,;;;:cloooooooooooooodxOKNMMMMMMNOl:;;;,,;;;;::cllooooddodddddolxXMMMMMMMMNkl;;;;;;;;::::ccllooddddddolo0WMMMMMMMMMWKx:,;;;;;;::cdxollllooooolco0MMMMMMMMMMXko;,,;;;;;::cOWNX0xlclllcccdXMMMMMMMMMMMN0d:,,,;;;;;:lkO00Oxlcccc:o0WMMMMMMMMMMMMMWKxc,,,;;;;;::::cccccc:o0NWWMMMMMMMMMMMMMMWO:,,,,;;;cooollllldxdoodxxxxxkXMMMMMMMMNx;,,;;;;;;:cc:cldOXXo;;:::::::oMMMMMMWOl;,,;;;::;;;:cdkKNMMWx::lk0kc:::MMMMWN0xoc;;cl::cc:okKWMMMMMMXkdodOKd:dxMMMMMMWWW0l:xKd:oocoxKMMMMMMMMMWNNWWK0NMMMMMMMMMMXxlO0lcdxdOXNMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKXOcoKNWMMMMMMMMMMMMMMMMMMMMM";
	if (poke_name == "charizard") emoji = "MMMMMMMWNKOOXMNKKKKXXNWMMMMMMWKOKWMMMMMMMMMMWKOdl:;dXWXkdollld0NWMMMWXd:cxXWMMMMMMNKdc;,''':OWMNKkocclkXWMMMNx;'',cdOXWMWKd:,,,,,'',o0NWMW0dodOWMMWNO:'',,,,;oKWXo,,,,,,,'',,:cdOXKkdxkKNXko:,'',;;,,,lKx;,:lddc,',,,,,,:oxxxddxxl;,,,,,:ll:;,;oclkKNWWKl,collcccldxxdxxdlccll:cON0ddo;:xXMMMMMMKkkkxdxkdoxkOO00OxkOkkdx0XOkXNdcNMMMMMMMMNOxk0NKxxkKXXXXX00NWX0O0KOO0XKOMMMMMMMMNKOkk0KOxxOXXXXXK0kOXWWWMN0KXNWWMMMMMMWXOxdddxxxook00000Oxook0XXK0KNMMMMMMMMMMWKxdddooooodkO000OkollldkO0XWMMMMMMMMMMMMWNKK0xolxKNNNWWWWN0dold0NMMMMMMMMMMMMMMMMMMMN0OkKWMMMMMMMMWX0OOKWMMMMMMMM";
	if (poke_name == "meowth") emoji = "MMMMMMMMMWWWMMWWMMMMMMWNWWX0kkXWMMMMMMMMMMMMMMMW0lcldO0XNNNNWNK0xl:;,'cKMMMMMMMMMMMMMMMKc.,:,';x00Okkxl;,;lxxc'oNMMMMMMMMMMMMMWx';xOkdoxO0OxxkkxkOO00o':0MMMMMMMMMMMMMNo.:OKKKK000kk0KXXXXKK0d',OMMMMMMMMMMMMMNd:xKNXKKK0OOKKK00NWNXK0o:kNNNNWWMMWWNNNXOOXWMKxOXXXXXKXxxNMMWXK0k0NNWWWMMMMMMMWNKKNMMKk0XXXXXKXO0WMWNXKXKNMMMMMMMMMMMMWXKKXNNNXKXXXXXXXXXNNXXXKK0XNNWMMMMMMWNNNNXKKKKKKKKKKKKKKKKKKKXXK0XNNNNNWWMMMWWWMMWNKKKKKKXXXXXXXKKKKKK00XWMMMMMMMMMMMMMMMMMWNXKKKKKKKKKK000000XWMMMMMMMMMMMMMMMMMMMMMWX0OkkOOOOkkO0XNWMMMMMMMMMMMMMMMMMMMMMMWNXK00KKKKKK00KXNWMMN0OO0NMMMMMMMMMMMMMWXKXNXXXXXXXXKXXXKXNXxlcco0WMMMMMMMMMMMMWXKXXXXXXXXXXXKXXKXNNOoclxXMMMMMMMMMMMMMMWXK0000K00K00KKKXNN0xod0NWMMMMMMMMMMMMMMWX0Okkkkkkkk0KK00KKOOKNWMMMMMMMMMMMMMMMMNK000KKKKKK00K00XWWMMMMMMMMMMMMMMMMMMMMWXKXNWMMMMMMMWXXXXWMMMMMMMMMMMMMMMMMMWWWNXKXWMMMMMMMMMNXXXWMMMMMMMMMMMMMMMXOkxxxk0KKXWMMMMMMMNKKKK0kkOO0NMMMMMMMMMXxlllldOKKNWMMMMMMMXK00OolllldKMMMMMM";
	if (poke_name == "psyduck") emoji = "MMMMMMMMMMMMMMMWWMKxxKMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXddKx;;xKddXMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOccc,,cccOWMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKx;,,,,;xKNWMMMMMMMMMMMMMMMMMMMMMMMNKOkkkkOOOOOOkkkkOKNMMMMMMMMMMMMMMMMMMNOkkOKKKKKKKKKKKXKKOkxOXMMMMMMMMMMMMMMN0xk0KK00000000000000KK0kxONMMMMMMMMMMMXxdO0000000000000000000000OdxXMMMMMMMMMNxd00kddxdxO0OxxxxO0Oxdxddk0OdxNMMMMMMMMOoO00Ok00OkOxdk00kdxOkO00kO00OoOMMMMMMMWxoO0000000Oddk0KK0kddO0000000OoxWMMMMMMWOoxOOO00kddk0OO00OO0kddk000OOxoOWMMMMMMMNxokkxddxkKKKKKKKKKKKKkxddxkkoxNMMMMMMMMMNkolox0KKKKKKKKKKKKKKKK0xolokNMMMMMMMMMMMNxo0KKKKKKKKKKKKKKKKKKKK0oxWMMMMMMMMMMMMNxdKKKKKKKKKKKKKKKKKKKKKKdxNMMMMMMMMMMMMWOd0XKKKKKKKKKKKKKKKKKKK0dOWMMMMMMMMMMMMMW0kkOKKXXXXXXXXXXXXKKOkk0WMMMMMMMMMMMMMMMMNK0OOOOOOOOOOOOOOOO0KNMMMMMMMMMMMMMMMMMMMMMMWNNXKKKKKKXNNWMMMMMMMMMMMMM";
	if (poke_name == "dragonite") emoji = "MMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMWWMMMMMWWWWWWWWNXNMMMMMMMMMMMMMMMMMMMMMWXXNNNNXK000XWWNNWWMMMMMMMMMMMMMMMMMMMMMMWNNWNKO0Oxk0NMMMMMWNNWMMMMMMMMMMMMMMMMMMMMMMWKO0OxdkKWMMMMKddOXWMMMMMMMMMMMMMMMMMMMMW0OOOkxx0NMMWKdllld0WMMMMMMMMMMMMMMWKKKXOlcdkOkkOKXKkollllooOWMMMMMMMMMMMMMNKOOkdlokKX0O00OxodxdoxOkxXMMMMMMMMMMMMMMWX0Okk0XXX0OO0000XNXXWMWXNMMMMMMMMMMMMMMMMMWNXXXXX0OOOOOO0KWMMMMWMMWWMMMMMMMMMMMMMMNXNNNNX0OOOkkOOOKWMMMMWX0KWMMMMMMMMMMMWXKXNNNXXKOOOOOkkOKWWWXKkxkNMMMMMMMMMMMMNK0KXNXXXK00000OOOOOOxdookXMMMMMMMMMMMMMN0O0KXXXXK0000000kdoooox0NMMMMMMMMMMMMMMWX0xxkO000kkkOOOOkdodk0NMMMMMMMMMMMMMMMWNNKkooxO0OkxxxxxxkOKNWMMMMMMMMMMMMMMMMMNK00OO0XWMWWNXK0kkOXMMMMMMMMMMMMMMMMMMMMMWWWWWMMMMMMMNK0OOk0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXKKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
	if (poke_name == "pikachu") emoji = "MMMMMMMMMMMMMMMMMMXko:.cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkooodKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKKK0KNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXK00KXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXK000KXNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0KKKKKKKKXNWMMMMMMMMMMMMMMMMMMMWWNNWWNOolk0KKKKKKKKKXNWMMMMMMMMMMMMMMMMNKKKKOddook000KKOkkO00KXNWMMMMMMMMMMMMMMNKKK0kooOOdclxO0kclOK00KKXWMMMMMMMMMMMMMNK0KK0OO0Oo::okOkolkKX0xolo0MMMMMMMMMMMMWX00KKK000kxk0K0dlld0K0OxlckWMMMMMMMMMMMMWKO0KKK00O000000OOOOO0KKKNMMMMMMMMMMMMMMMN0OKKKK0000KKKKKKKK0OOKNMMMMMMMMMMMMMMMMNK0KKKKKKKKKKK0OO0000KNMMMMMMMMMMMMMMMMWXKKKKKKKKKKKKK0kdOXXNWMMMMMMMMMMMMMMMMWXKKKKKKKKKKKKKKK0KNMMMMMMMMMMMMMMMMMMMMNK0KKKKKKKKKKKKKKKNMMMMMMMMMMMMMMMMMMMMMWKOkOkOOkOOOOOOOO0NMMMMMMMMMMMMMMMMMMMMWX0OkO0KKKKK0Okxxx0NWMMMMMMMMMMMMMMMMMMMWXXNNWWMMMMMMWXK0OO0XMMMMMMMMMMMMMM";
	if (poke_name == "chikorita") emoji = "MMMMMMMMMMN0kdocccccccclodkO0XNMMMMMMMMMMMMMMMMN0xodxxxdl:clooddddddddkOKWMMMMMMMMMWXXX0xxOKKXNWXOo:;:lddddddddddk0NMMMMMN00KXXNNX0dlx0XNMW0ko::oddddddddddkKWMMXoc0NNNNNKkc;lOKKNMMMNOc:coddddddddddONMk;cKNNNNX0kl,;xXKKWMMMWXx::ldddddddoddONx:dKNNNNX0OdloOXX0XMMMMMWKo:codddddocldO0kOxollox0XXXXXNNKKWMMMMMMW0dlloddddl:cdKKXk;..,cONNNNNXNKk0NWMMMMMMWKkooddddl::XKXXk::ld0NNNNNXKOxOXNMMWMMMMMMXOoodddc,kOXNX0kk0XNXXXXKxxO00KK0XWMMMMMMWXxoddo:OkOOKNNXXXNKkdOK00KK0K0kKMMMMMMMMMWOoddoXOdd0NKxdOXXOkO0KXXNNNKO0XNWMMMMMMMWkookX0XXNNX0OKXNNXKXNNNNNX00Okk0NMMMMMMMXddKX0XNNNNNNNNNNNXXKK0OOO0XX0xkXMMMMMMMNOKWNKXKKXNNNXNNNXKOkxxkO0XNNX0ONMMMMMMMWWMMWK0OxOKXXXNNNXXK0O0XXNXXXXXKXMMMMMMMMMMMMN0Okddxk00KKXXXXXXKKK0OO0XKKWMMMMMMMMMMMMXOkkxxddkkxxxkkxkkxxxkkk0KXMMMMMMMMMMMMMMXkxxxkKNXxoddxOKKKOxxxxOXWMMMMMMMMMMMMMMNkoxONMMW0xk0XWMMMWXxod0WMMMMMMMMMMMM";
}

string Pokemon::getEmoji()
{
	return emoji;
}

int Pokemon::getNumLine()
{
	return num_lines_emoji;
}


void Pokemon::setBaseStat(string name, int num) {
	if (name == "hp") setHealthPoint(num);
	if (name == "attack") setAttack(num);
	if (name == "defense") setDefense(num);
	if (name == "special-attack") setSpecialAttack(num);
	if (name == "special-defense") setSpecialDefense(num);
	if (name == "speed") setSpeed(num);


}

CatchedPokemon::CatchedPokemon() {

	this->remain_hp = health_point;
	this->alive = true;
}
CatchedPokemon::CatchedPokemon(string name) :Pokemon(name) {
	this->remain_hp = health_point;
	this->alive = true;
}
CatchedPokemon::CatchedPokemon(Pokemon& pokemon) {
	this->remain_hp = health_point;
	this->alive = true;
	this->name = pokemon.getName();
	this->health_point = pokemon.getHealthPoint();
	this->attack = pokemon.getAttack();
	this->defense = pokemon.getDefense();
	this->special_attack = pokemon.getSpecialAttack();
	this->special_defense = pokemon.getSpecialDefense();
	this->speed = pokemon.getSpeed();
	this->type1 = pokemon.getType1();
	this->type2 = pokemon.getType2();
	this->moves[0] = pokemon.getSkill(0);
	this->moves[1] = pokemon.getSkill(1);
	this->moves[2] = pokemon.getSkill(2);
	this->moves[3] = pokemon.getSkill(3);

}
CatchedPokemon::~CatchedPokemon() {


}
void CatchedPokemon::setAlive(bool life) {
	if (life) {
		this->alive = true;
		this->remain_hp = this->health_point;
	}
	else {
		this->alive = false;
	}
}
bool CatchedPokemon::Alive() {
	return this->alive;
}

void CatchedPokemon::setRemainHp(int remain_hp) {
	this->remain_hp = remain_hp;


}
int CatchedPokemon::getRemainHp() {
	return this->remain_hp;
}
void CatchedPokemon::reset() {
	this->setAlive(true);
	for (int i = 0; i < 4; i++) {
		this->moves[i]->resetPP();
	}
}
