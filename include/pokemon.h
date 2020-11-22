#ifndef POKEMON_H
#define POKEMON_H

#include"skill.h"
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


private:
	string name;
	Type type1;
	Type type2;
	int lv;
	int health_point;
	int attack;
	int block;
	int contact;
	int defense;
	int speed;
	int base_health_point;
	int base_attack;
	int base_block;
	int base_contact;
	int base_defense;
	int base_speed;
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
	double GetRemainHp();
	int GetHealthPoint();
	int GetAttack();
	int GetBlock();
	int GetContact();
	int GetDefense();
	int GetSpeed();
	Type GetType1();
	Type GetType2();
	bool Alive();
	void ShowInfo();
	Skill GetSkill1();
	Skill GetSkill2();
	Skill GetSkill3();
	Skill GetSkill4();

};
#endif 

