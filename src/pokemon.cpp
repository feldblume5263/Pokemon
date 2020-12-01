#include"../include/pokemon.h"
#include<random>
#include<cmath>
#include<iostream>

Pokemon::Pokemon() {
	////from database//////////
	//this->name = "Pikachu";
	//this->base_health_point = 35;
	//this->base_attack = 55;
	//this->base_block = 40;
	//this->base_contact = 50;
	//this->base_defense = 50;
	//this->base_speed = 90;
	//this->type1 = Electric;
	//this->type2 = None;
	///////////////////////////
	//setIndiStat();
	//setEffStat();
	//setNature();
	//setStat();
	//for (int i = 0; i < 4; i++) {
	//	this->moves[i] = new Skill();
	//}
	num_of_skill = 0;
}
Pokemon::Pokemon(string name) {


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
	this->indi_block = dis(gen);
	this->indi_contact = dis(gen);
	this->indi_defense = dis(gen);
	this->indi_speed = dis(gen);
}
void Pokemon::setEffStat() {
	this->eff_health_point = 0;
	this->eff_attack = 0;
	this->eff_block = 0;
	this->eff_contact = 0;
	this->eff_defense = 0;
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
			if (this->eff_block < 253) {
				this->eff_block++;


			}
			continue;
		case 4:
			if (this->eff_contact < 253) {
				this->eff_contact++;

			}
			continue;
		case 5:
			if (this->eff_defense < 253) {
				this->eff_defense++;

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
	block = (int)ceil((((double)base_block * 2 + (double)indi_block + (double)eff_block / 4) / 2 + 5) * nature_stat_rate[getNature()][1]);
	contact = (int)ceil((((double)base_contact * 2 + (double)indi_contact + (double)eff_contact / 4) / 2 + 5) * nature_stat_rate[getNature()][2]);
	defense = (int)ceil((((double)base_defense * 2 + (double)indi_defense + (double)eff_defense / 4) / 2 + 5) * nature_stat_rate[getNature()][3]);
	speed = (int)ceil((((double)base_speed * 2 + (double)indi_speed + (double)eff_speed / 4) / 2 + 5) * nature_stat_rate[getNature()][4]);


}

int Pokemon::getHealthPoint() {
	return this->health_point;
}
int Pokemon::getAttack() {
	return this->attack;
}
int Pokemon::getBlock() {
	return this->block;
}
int Pokemon::getContact() {
	return this->contact;
}
int Pokemon::getDefense() {
	return this->defense;
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
void Pokemon::setBlock(int num) {
	this->base_block = num;
}
void Pokemon::setContact(int num) {
	this->base_contact = num;

}
void Pokemon::setDefense(int num) {
	this->base_defense = num;
}
void Pokemon::setSpeed(int num) {
	this->base_speed = num;
}
void Pokemon::setType1(string name) {

	this->type1 = searchType(name);
}
void Pokemon::setType2(string name) {

	this->type1 = searchType(name);
}
void Pokemon::setSkill(int idx, Skill* skill) {
	this->moves[idx] = skill;
	idx++;
}



void Pokemon::showInfo() {
	cout << this->name << endl;
	cout << "hp:" << this->health_point << endl;

	cout << "attack:" << this->attack << endl;

	cout << "block:" << this->block << endl;

	cout << "contact:" << this->contact << endl;

	cout << "defense:" << this->defense << endl;

	cout << "speed:" << this->speed << endl;

	for (int i = 0; i < 4; i++) {
		this->moves[i]->showInfo();
	}
}
Skill* Pokemon::getSkill1() {
	return this->moves[0];
}

Skill* Pokemon::getSkill2() {
	return this->moves[1];
}

Skill* Pokemon::getSkill3() {
	return this->moves[2];
}
Skill* Pokemon::getSkill4() {
	return this->moves[3];
}



void Pokemon::setBaseStat(string name, int num) {
	if (name == "hp") setHealthPoint(num);
	if (name == "attack") setAttack(num);
	if (name == "defense") setBlock(num);
	if (name == "special-attack") setContact(num);
	if (name == "special-defense") setDefense(num);
	if (name == "speed") setSpeed(num);


}










CatchedPokemon::CatchedPokemon() {
	Pokemon();
	this->remain_hp = health_point;
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

void CatchedPokemon::setRemainHp(double rate) {
	if (this->remain_hp - (int)ceil(this->remain_hp * rate) > 0) {
		this->remain_hp = (int)(this->remain_hp - ceil(this->remain_hp * rate));
	}
	else {
		this->remain_hp = 0;
		this->setAlive(false);
	}

}
void CatchedPokemon::setRemainHp(int potion) {
	this->remain_hp = this->remain_hp + potion;
	if (this->remain_hp > this->getHealthPoint()) {
		this->remain_hp = this->getHealthPoint();
	}


}
double CatchedPokemon::getRemainHp() {
	return this->remain_hp;
}
void CatchedPokemon::reset() {
	this->setAlive(true);
	for (int i = 0; i < 4; i++) {
		this->moves[i]->resetPP();
	}
}


bool CatchedPokemon::attack(CatchedPokemon& target, Skill* attack) {
	double attack_power;
	double defense_power;
	double rate;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	uniform_int_distribution<int> dis_1(85, 100);
	if (dis(gen) < attack->getAccuracy()) {

		if (attack->getDamageType() == Physical) {

			if (this->getType1() == attack->getType() || this->getType2() == attack->getType()) {
				attack_power = ceil((double)(this->getAttack() * attack->getPower() * 1.5) * (double)dis_1(gen) / 100);
			}
			else {
				attack_power = ceil((double)(this->getAttack() * attack->getPower()) * (double)dis_1(gen) / 100);
			}
			defense_power = ceil(target.getBlock() * target.getRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack->getType()][target.getType1()] *
				type_damage_rate[attack->getType()][target.getType2()];
			target.setRemainHp(rate);

		}
		else {

			if (this->getType1() == attack->getType() || this->getType2() == attack->getType()) {
				attack_power = ceil((double)(this->getContact() * attack->getPower() * 1.5) * (double)dis_1(gen) / 100);
			}
			else {
				attack_power = ceil((double)(this->getContact() * attack->getPower()) * (double)dis_1(gen) / 100);
			}
			defense_power = ceil(target.getDefense() * target.getRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack->getType()][target.getType1()] *
				type_damage_rate[attack->getType()][target.getType2()];
			target.setRemainHp(rate);

		}
		return true;
	}
	else {

		false;
	}



}

//int main() {
//
//
//	CatchedPokemon test = CatchedPokemon();
//	CatchedPokemon test1 = CatchedPokemon();
//	test1.showInfo();
//	test.attack(test1,test.getSkill1());
//	cout << "////////////////////////////////////////////\n";
//	test1.showInfo();
//	test.attack(test1,test.getSkill1());
//	cout << "////////////////////////////////////////////\n";
//	test1.showInfo();
//	return 0;
//}
//
//

