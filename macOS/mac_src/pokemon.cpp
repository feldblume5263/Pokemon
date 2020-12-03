#include"../include/pokemon.h"
#include<random>
#include<cmath>
#include<iostream>





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

//void CatchedPokemon::setRemainHp(double rate) {
//	if (this->remain_hp - (int)ceil(this->remain_hp * rate) > 0) {
//		this->remain_hp = (int)(this->remain_hp - ceil(this->remain_hp * rate));
//	}
//	else {
//		this->remain_hp = 0;
//		this->setAlive(false);
//	}
//
//}
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


//bool CatchedPokemon::attack(CatchedPokemon& target, Skill* attack) {
//	double attack_power;
//	double defense_power;
//	double rate;
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int> dis(0, 99);
//	uniform_int_distribution<int> dis_1(85, 100);
//	if (dis(gen) < attack->getAccuracy()) {
//
//		if (attack->getDamageType() == Physical) {
//
//			if (this->getType1() == attack->getType() || this->getType2() == attack->getType()) {
//				attack_power = ceil((double)(this->getAttack() * attack->getPower() * 1.5) * (double)dis_1(gen) / 100);
//			}
//			else {
//				attack_power = ceil((double)(this->getAttack() * attack->getPower()) * (double)dis_1(gen) / 100);
//			}
//			defense_power = ceil(target.getBlock() * target.getRemainHp() / 0.411);
//			rate = attack_power / defense_power * type_damage_rate[attack->getType()][target.getType1()] *
//				type_damage_rate[attack->getType()][target.getType2()];
//			target.setRemainHp(rate);
//
//		}
//		else {
//
//			if (this->getType1() == attack->getType() || this->getType2() == attack->getType()) {
//				attack_power = ceil((double)(this->getContact() * attack->getPower() * 1.5) * (double)dis_1(gen) / 100);
//			}
//			else {
//				attack_power = ceil((double)(this->getContact() * attack->getPower()) * (double)dis_1(gen) / 100);
//			}
//			defense_power = ceil(target.getDefense() * target.getRemainHp() / 0.411);
//			rate = attack_power / defense_power * type_damage_rate[attack->getType()][target.getType1()] *
//				type_damage_rate[attack->getType()][target.getType2()];
//			target.setRemainHp(rate);
//
//		}
//		return true;
//	}
//	else {
//
//		false;
//	}
//
//
//
//}
//
//int main() {
//
//	
//	CatchedPokemon test = CatchedPokemon();
//	CatchedPokemon test1 = CatchedPokemon();
//	CatchedPokemon test2 = CatchedPokemon();
//	test.showInfo();
//	cout << "////////////////////////////////////////////\n";
//	test1.showInfo();
//	cout << "////////////////////////////////////////////\n";
//	test2.showInfo();
//	return 0;
//}
//


