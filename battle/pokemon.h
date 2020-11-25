#pragma once

#include<random>
#include<cmath>
#include"skill.h"

enum Nature {
	Lonely,
	Adamant,
	Naughty,
	Brave,
	Bold,
	Impish,
	Lax,
	Relaxed,
	Modest,
	Mild,
	Rash,
	Quiet,
	Calm,
	Gentle,
	Careful,
	Sassy,
	Timid,
	Hasty,
	Jolly,
	Naive,
	Bashful,
	Hardy,
	Docile,
	Quirky,
	Serious
};


//double nature_stat_rate[25][5] = {
//	//				a		b		c		d		s
//					{1.1,	0.9,	1.0,	1.0,	1.0},
//					{1.1,	1.0,	0.9,	1.0,	1.0},
//					{1.1,	1.0,	1.0,	0.9,	1.0},
//					{1.1,	1.0,	1.0,	1.0,	0.9},
//					{0.9,	1.1,	1.0,	1.0,	1.0},
//					{1.0,	1.1,	0.9,	1.0,	1.0},
//					{1.0,	1.1,	1.0,	0.9,	1.0},
//					{1.0,	1.1,	1.0,	1.0,	0.9},
//					{0.9,	1.0,	1.1,	1.0,	1.0},
//					{1.0,	0.9,	1.1,	1.0,	1.0},
//					{1.0,	1.0,	1.1,	0.9,	1.0},
//					{1.0,	1.0,	1.1,	1.0,	0.9},
//					{0.9,	1.0,	1.0,	1.1,	1.0},
//					{1.0,	0.9,	1.0,	1.1,	1.0},
//					{1.0,	1.0,	0.9,	1.1,	1.0},
//					{1.0,	1.0,	1.0,	1.1,	0.9},
//					{0.9,	1.0,	1.0,	1.0,	1.1},
//					{1.0,	0.9,	1.0,	1.0,	1.1},
//					{1.0,	1.0,	0.9,	1.0,	1.1},
//					{1.0,	1.0,	1.0,	0.9,	1.1},
//					{1.0,	1.0,	1.0,	1.0,	1.0},
//					{1.0,	1.0,	1.0,	1.0,	1.0},
//					{1.0,	1.0,	1.0,	1.0,	1.0},
//					{1.0,	1.0,	1.0,	1.0,	1.0},
//					{1.0,	1.0,	1.0,	1.0,	1.0}
//
//
//
//};
//double type_damage_rate[19][19] = {
//	//			Normal	Fire	Water	Elect	Grass	Ice		Fight	Poison	Ground	Flying	Psych	Bug		Rock	Ghost	Dragon	Dark	Steel	Fiary	None
//	/*Normal*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	0.0,	1.0,	0.5,	1.0,	1.0},
//	/*Fire*/	{1.0,	0.5,	0.5,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	2.0,	1.0,	1.0},
//	/*Water*/	{1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0},
//	/*Elect*/	{1.0,	1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0},
//	/*Grass*/	{1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	1.0,	0.5,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0,	1.0},
//	/*Ice*/		{1.0,	0.5,	0.5,	1.0,	2.0,	0.5,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0},
//	/*Fight*/	{2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	0.5,	0.5,	2.0,	0.0,	1.0,	2.0,	2.0,	0.5,	1.0},
//	/*Poison*/	{1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	0.0,	2.0,	1.0},
//	/*Ground*/	{1.0,	2.0,	1.0,	2.0,	0.5,	1.0,	1.0,	2.0,	1.0,	0.0,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0},
//	/*Flying*/	{1.0,	1.0,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0},
//	/*Psychic*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	0.0,	0.5,	1.0,	1.0},
//	/*Bug*/		{1.0,	0.5,	1.0,	1.0,	2.0,	1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	0.5,	1.0,	2.0,	0.5,	0.5,	1.0},
//	/*Rock*/	{1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0},
//	/*Ghost*/	{0.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0},
//	/*Dragon*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	0.0,	1.0},
//	/*Dark*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0},
//	/*Steel*/	{1.0,	0.5,	0.5,	0.5,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	2.0,	1.0},
//	/*Fairy*/	{1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	0.5,	1.0,	1.0},
//	/*None*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0}
//};

class Pokemon {
public:
	std::string emoji =
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
		"MMMMMMMMMMMMMMMMWWNNNNWWMMMMMMMMMMMMMMMM"
		"MMMMMMMMMMMWNWWN0OOOOOO0NWNNWMMMMMMMMMMM"
		"MMMNXXNWMMMN0KNKkkkkkkkkKNK0NMMMWNXXNMMM"
		"MMKo;:cldOXN0KNKkkkkkkkkKNK0NXOdlc:;oKMM"
		"MNd,;lolc;cxO0X0kkkkkkkk0X0Oxc;clol;,dNM"
		"MKl,ckkkkxxOO0K0kkkkkkkk0K0OOxxkkkkc'lKM"
		"MXo,:dkOKXXXKKX0kkkkkkkk0XXKXXXKOkd:,oXM"
		"MWO:,ckKXXXXXXXKOkkkkkkOKXXXXXXXKkc,c0WM"
		"MMWKddKXXX0OO0XXXKKKKKKXXXKOO0XXXKddKWMM"
		"NXNNXXXXXkxo;:kXXXXXXXXXXOxo::kXXXXNNNXN"
		"NXKK0000Kkl;,:kXXXXXXXXXXkl;,ckK000KKKXN"
		"MMMWNXKKKX0kk0XXNNNNNNNNXX0kk0XKKKXNWMMM"
		"WNNXK000KXKkxO00KKKKKKKK00OxkKXK000KXNNW"
		"NKKXXXXXXXX0kdodxxxxxxxxdodx0XXXXXXXXKKN"
		"MMMMMMWWNNXXX0O0XXXXXXXX0O0XXXXNWMMMMMMM"
		"MMMMMMMMMWWNNXXXXXXXXXXXXXXNNWWMMMMMMMMM"
		"MMMMMMMMMMMMWWWWNNNNNNNNWWWWMMMMMMMMMMMM"
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"
		"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";

	double nature_stat_rate[25][5] = {
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

	double type_damage_rate[19][19] = {
		//			Normal	Fire	Water	Elect	Grass	Ice		Fight	Poison	Ground	Flying	Psych	Bug		Rock	Ghost	Dragon	Dark	Steel	Fiary	None
		/*Normal*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	0.0,	1.0,	0.5,	1.0,	1.0},
		/*Fire*/	{1.0,	0.5,	0.5,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	2.0,	1.0,	1.0},
		/*Water*/	{1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0},
		/*Elect*/	{1.0,	1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0},
		/*Grass*/	{1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	1.0,	0.5,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0,	1.0},
		/*Ice*/		{1.0,	0.5,	0.5,	1.0,	2.0,	0.5,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0},
		/*Fight*/	{2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	0.5,	0.5,	2.0,	0.0,	1.0,	2.0,	2.0,	0.5,	1.0},
		/*Poison*/	{1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	0.0,	2.0,	1.0},
		/*Ground*/	{1.0,	2.0,	1.0,	2.0,	0.5,	1.0,	1.0,	2.0,	1.0,	0.0,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0},
		/*Flying*/	{1.0,	1.0,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0},
		/*Psychic*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	0.0,	0.5,	1.0,	1.0},
		/*Bug*/		{1.0,	0.5,	1.0,	1.0,	2.0,	1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	0.5,	1.0,	2.0,	0.5,	0.5,	1.0},
		/*Rock*/	{1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0},
		/*Ghost*/	{0.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0},
		/*Dragon*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	0.0,	1.0},
		/*Dark*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0},
		/*Steel*/	{1.0,	0.5,	0.5,	0.5,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	2.0,	1.0},
		/*Fairy*/	{1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	0.5,	1.0,	1.0},
		/*None*/	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0}
	};
private:
	//from database///////////
	string name;
	Type type1;
	Type type2;
	int base_health_point;
	int base_attack;
	int base_block;
	int base_contact;
	int base_defense;
	int base_speed;
	//////////////////////////
	Nature nature;
	int lv;
	int health_point;
	int attack;
	int block;
	int contact;
	int defense;
	int speed;
	int indi_health_point;
	int indi_attack;
	int indi_block;
	int indi_contact;
	int indi_defense;
	int indi_speed;
	int eff_health_point;
	int eff_attack;
	int eff_block;
	int eff_contact;
	int eff_defense;
	int eff_speed;
	Skill moves[4];
	bool alive;
	int remain_hp;



	int special_attack;
	int special_defense;
	

public:
	Pokemon();
	Pokemon(string name);
	~Pokemon();
	void SetStat();
	void SetIndiStat();
	void SetEffStat();
	bool Attack(Pokemon& target, Skill attack);
	void SetAlive(bool life);
	void SetRemainHp(double rate);
	// change
	void SetRemainHp(int _remain_hp);
	void SetNature();
	// change to int
	int GetRemainHp();
	int GetHealthPoint();
	int GetAttack();
	int GetBlock();
	int GetContact();
	int GetDefense();
	int GetSpeed();
	Type GetType1();
	Type GetType2();
	Nature GetNature();
	bool Alive();
	void ShowInfo();
	Skill GetSkill1();
	Skill GetSkill2();
	Skill GetSkill3();
	Skill GetSkill4();
	void Reset();


	// chagne
	string GetName();
	Skill& GetSkill(int i);
	void SetSpecialAttack(int _special_attack);
	int GetSpecialAttack();
	void SetSpecialDefense(int _special_attack);
	int GetSpecialDefense();
	void gyarados();
	void charizard();


};
