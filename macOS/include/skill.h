#ifndef SKILL_H
#define SKILL_H

#include<string>
using namespace std;
enum Type {
	Normal,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Fighting,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,
	Fairy,
	None
};

enum DamageType {
	Physical,
	Special
};



class Skill {
private:
	string name;
	int power;
	int accuracy;
	Type type;
	DamageType damage_type;
	int pp;
	int remain_pp;

	// add isSkill chnage
	bool isSkill;



public:
	Skill();
	Skill(string name);
	~Skill();
	string getName();
	int getPower();
	double getAccuracy();
	Type getType();
	DamageType getDamageType();
	// change delete
	//int getRemainPP();
	void setName(string name);
	void setPower(int power);
	void setAccuracy(int accuracy);
	void setType(string type_name);
	void setDamageType(string damage_type_name);
	void setPP(int pp);
	void showInfo();
	void resetPP();
	void setRemainPP(int remain_pp);
	int getRemainPP();
	int getPP();
	// change Get -> get  above two functions
	void reducePP();
	bool noPP();

};
Type searchType(string type);
DamageType searchDamageType(string damage_type);
#endif

