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
	//SetIndiStat();
	//SetEffStat();
	//SetNature();
	//SetStat();
	//for (int i = 0; i < 4; i++) {
	//	this->moves[i] = Skill();
	//}
}
Pokemon::Pokemon(string name) {
	//데이터 베이스에서 가져옴

}
Pokemon::~Pokemon() {}

void Pokemon::SetIndiStat() {
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
void Pokemon::SetEffStat() {
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


void Pokemon::SetNature() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 24);
	int num = dis(gen);
	this->nature = static_cast<Nature>(num);
	cout << this->nature << endl;


}

Nature Pokemon::GetNature() {
	return this->nature;
}
void Pokemon::SetStat() {

	health_point = ceil(((double)base_health_point * 2 + (double)indi_health_point + (double)eff_health_point / 4) / 2 + 10 + 50);
	attack = (int)ceil((((double)base_attack * 2 + (double)indi_attack + (double)eff_attack / 4) / 2 + 5) * nature_stat_rate[GetNature()][0]);
	block = (int)ceil((((double)base_block * 2 + (double)indi_block + (double)eff_block / 4) / 2 + 5) * nature_stat_rate[GetNature()][1]);
	contact = (int)ceil((((double)base_contact * 2 + (double)indi_contact + (double)eff_contact / 4) / 2 + 5) * nature_stat_rate[GetNature()][2]);
	defense = (int)ceil((((double)base_defense * 2 + (double)indi_defense + (double)eff_defense / 4) / 2 + 5) * nature_stat_rate[GetNature()][3]);
	speed = (int)ceil((((double)base_speed * 2 + (double)indi_speed + (double)eff_speed / 4) / 2 + 5) * nature_stat_rate[GetNature()][4]);


}
void CatchedPokemon::SetAlive(bool life) {
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

int Pokemon::GetHealthPoint() {
	return this->health_point;
}
int Pokemon::GetAttack() {
	return this->attack;
}
int Pokemon::GetBlock() {
	return this->block;
}
int Pokemon::GetContact() {
	return this->contact;
}
int Pokemon::GetDefense() {
	return this->defense;
}
int Pokemon::GetSpeed() {
	return this->speed;
}
Type Pokemon::GetType1() {
	return this->type1;
}
Type Pokemon::GetType2() {
	return this->type2;
}
void Pokemon::SetName(string name) {
	this->name = name;
}
void Pokemon::SetHealthPoint(int num) {
	this->base_health_point = num;
}
void Pokemon::SetAttack(int num) {
	this->base_attack = num;

}
void Pokemon::SetBlock(int num) {
	this->base_block = num;
}
void Pokemon::SetContact(int num) {
	this->base_contact = num;

}
void Pokemon::SetDefense(int num) {
	this->base_defense = num;
}
void Pokemon::SetSpeed(int num) {
	this->base_speed = num;
}
void Pokemon::SetType1(wstring name) {
	string type_name;
	type_name.assign(name.begin(), name.end());
	this->type1 = SearchType(type_name);
}
void Pokemon::SetType2(wstring name) {
	string type_name;
	type_name.assign(name.begin(), name.end());
	this->type1 = SearchType(type_name);
}
void Pokemon::SetSkill1(Skill& skill) {
	this->moves[0] = skill;
}
void Pokemon::SetSkill2(Skill& skill) {
	this->moves[0] = skill;
}
void Pokemon::SetSkill3(Skill& skill) {
	this->moves[0] = skill;
}
void Pokemon::SetSkill4(Skill& skill) {
	this->moves[0] = skill;
}



void Pokemon::ShowInfo() {
	cout << this->name << endl;
	cout << "hp:" << this->health_point << endl;

	cout << "attack:" << this->attack << endl;

	cout << "block:" << this->block << endl;

	cout << "contact:" << this->contact << endl;

	cout << "defense:" << this->defense << endl;

	cout << "speed:" << this->speed << endl;

	for (int i = 0; i < 4; i++) {
		this->moves[i].ShowInfo();
	}
}
Skill Pokemon::GetSkill1() {
	return this->moves[0];
}

Skill Pokemon::GetSkill2() {
	return this->moves[1];
}

Skill Pokemon::GetSkill3() {
	return this->moves[2];
}
Skill Pokemon::GetSkill4() {
	return this->moves[3];
}


void CatchedPokemon::SetRemainHp(double rate) {
	if (this->remain_hp - (int)ceil(this->remain_hp * rate) > 0) {
		this->remain_hp = (int)(this->remain_hp - ceil(this->remain_hp * rate));
	}
	else {
		this->remain_hp = 0;
		this->SetAlive(false);
	}

}
void CatchedPokemon::SetRemainHp(int potion) {
	this->remain_hp = this->remain_hp + potion;
	if (this->remain_hp > this->GetHealthPoint()) {
		this->remain_hp = this->GetHealthPoint();
	}


}
double CatchedPokemon::GetRemainHp() {
	return this->remain_hp;
}
void CatchedPokemon::Reset() {
	this->SetAlive(true);
	for (int i = 0; i < 4; i++) {
		this->moves[i].ResetPP();
	}
}


bool CatchedPokemon::Attack(CatchedPokemon& target, Skill attack) {
	double attack_power;
	double defense_power;
	double rate;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	uniform_int_distribution<int> dis_1(85, 100);
	if (dis(gen) < attack.GetAccuracy()) {

		if (attack.GetDamageType() == Physical) {

			if (this->GetType1() == attack.GetType() || this->GetType2() == attack.GetType()) {
				attack_power = ceil((double)(this->GetAttack() * attack.GetPower() * 1.5) * (double)dis_1(gen) / 100);
			}
			else {
				attack_power = ceil((double)(this->GetAttack() * attack.GetPower()) * (double)dis_1(gen) / 100);
			}
			defense_power = ceil(target.GetBlock() * target.GetRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack.GetType()][target.GetType1()] *
				type_damage_rate[attack.GetType()][target.GetType2()];
			target.SetRemainHp(rate);

		}
		else {

			if (this->GetType1() == attack.GetType() || this->GetType2() == attack.GetType()) {
				attack_power = ceil((double)(this->GetContact() * attack.GetPower() * 1.5) * (double)dis_1(gen) / 100);
			}
			else {
				attack_power = ceil((double)(this->GetContact() * attack.GetPower()) * (double)dis_1(gen) / 100);
			}
			defense_power = ceil(target.GetDefense() * target.GetRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack.GetType()][target.GetType1()] *
				type_damage_rate[attack.GetType()][target.GetType2()];
			target.SetRemainHp(rate);

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
//	test1.ShowInfo();
//	test.Attack(test1,test.GetSkill1());
//	cout << "////////////////////////////////////////////\n";
//	test1.ShowInfo();
//	test.Attack(test1, test.GetSkill1());
//	cout << "////////////////////////////////////////////\n";
//	test1.ShowInfo();
//	return 0;
//}



