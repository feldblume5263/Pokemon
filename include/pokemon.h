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
	Skill* moves[4];
	int num_of_skill;
	void setAttack(int num);
	void setBlock(int num);
	void setContact(int num);
	void setDefense(int num);
	void setSpeed(int num);

public:
	Pokemon();
	Pokemon(string name);
	~Pokemon();
	void setStat();
	void setIndiStat();
	void setEffStat();
	void setNature();
	int getHealthPoint();
	int getAttack();
	int getBlock();
	int getContact();
	int getDefense();
	int getSpeed();
	void setName(string name);
	void setHealthPoint(int num);
	void setBaseStat(string name, int num);
	void setType1(string name);
	void setType2(string name);
	void setSkill(int idx, Skill* skill);
	Type getType1();
	Type getType2();
	Nature getNature();
	void showInfo();
	Skill* getSkill1();
	Skill* getSkill2();
	Skill* getSkill3();
	Skill* getSkill4();



};


class CatchedPokemon :public Pokemon {
private:
	bool alive;
	int remain_hp;

public:
	CatchedPokemon();
	CatchedPokemon(string name);
	~CatchedPokemon();

	void setRemainHp(double rate);
	void setRemainHp(int potion);
	double getRemainHp();
	bool attack(CatchedPokemon& target, Skill* attack);
	void setAlive(bool life);
	bool Alive();
	void reset();
};
#endif 

