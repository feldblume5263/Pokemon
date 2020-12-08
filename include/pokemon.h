#ifndef POKEMON_H
#define POKEMON_H

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

class Pokemon {
protected:
	string name;
	Type type1;
	Type type2;
	int base_health_point;
	int base_attack;
	int base_defense;
	int base_special_attack;
	int base_special_defense;
	int base_speed;
	
	Nature nature;
	int lv;
	int health_point;
	int attack;
	int defense;
	int special_attack;
	int special_defense;
	int speed;
	int indi_health_point;
	int indi_attack;
	int indi_defense;
	int indi_special_attack;
	int indi_special_defense;
	int indi_speed;
	int eff_health_point;
	int eff_attack;
	int eff_defense;
	int eff_special_attack;
	int eff_special_defense;
	int eff_speed;
	Skill* moves[4];
	int num_of_skill;
	void setAttack(int num);
	void setDefense(int num);
	void setSpecialAttack(int num);
	void setSpecialDefense(int num);
	void setSpeed(int num);

	int num_lines_emoji = 20;
	std::string emoji;
public:
	Pokemon();
	Pokemon(string name);
	~Pokemon();
	void setStat();
	void setIndiStat();
	void setEffStat();
	void setNature();
	string getName();
	int getHealthPoint();
	int getAttack();
	int getDefense();
	int getSpecialAttack();
	int getSpecialDefense();
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
	Skill* getSkill(int idx);


	void setEmoji(string poke_name);
	string getEmoji();
	int getNumLine();
};


class CatchedPokemon :public Pokemon {
private:
	bool alive;
	int remain_hp;

public:
	CatchedPokemon();
	CatchedPokemon(string _name);
	CatchedPokemon(Pokemon& pokemon);
	~CatchedPokemon();

	/*void setRemainHp(double rate);*/
	void setRemainHp(int remain_hp);
	int getRemainHp();
	/*bool attack(CatchedPokemon& target, Skill* attack);*/
	void setAlive(bool life);
	bool Alive();
	void reset();
};
#endif 

