#ifndef POKEMON_H
#define POKEMON_H

#include"../include/skill.h"

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

class Pokemon {


protected:
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




public:
	Pokemon();
	Pokemon(string name);
	~Pokemon();
	void SetStat();
	void SetIndiStat();
	void SetEffStat();
	void SetNature();
	int GetHealthPoint();
	int GetAttack();
	int GetBlock();
	int GetContact();
	int GetDefense();
	int GetSpeed();
	void SetName(string name);
	void SetHealthPoint(int num);
	void SetAttack(int num);
	void SetBlock(int num);
	void SetContact(int num);
	void SetDefense(int num);
	void SetSpeed(int num);
	void SetType1(wstring name);
	void SetType2(wstring name);
	void SetSkill1(Skill& skill);
	void SetSkill2(Skill& skill);
	void SetSkill3(Skill& skill);
	void SetSkill4(Skill& skill);
	Type GetType1();
	Type GetType2();
	Nature GetNature();
	void ShowInfo();
	Skill GetSkill1();
	Skill GetSkill2();
	Skill GetSkill3();
	Skill GetSkill4();



};


class CatchedPokemon :public Pokemon {
private:
	bool alive;
	int remain_hp;

public:
	CatchedPokemon() {
		Pokemon();
		this->remain_hp = health_point;
	}
	CatchedPokemon(string name) {

	}
	void SetRemainHp(double rate);
	void SetRemainHp(int potion);
	double GetRemainHp();
	bool Attack(CatchedPokemon& target, Skill attack);
	void SetAlive(bool life);
	bool Alive();
	void Reset();
};
#endif 

